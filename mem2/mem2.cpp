#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <inttypes.h>

#define NTHREADS  100
#define ALLOCSIZE  16384
#define STRAGGLERS  100

static uint cpus;
static uint pages;
static uint pagesize;

static uint nallocs;

static volatile int go;
static volatile int done;
static volatile int spin;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void **ps;		// allocations that are freed in turn by each thread
static int nps;
static void **ss;		// straggling allocations to prevent arena free
static int nss;

void
my_sleep (int ms)
{
  int rv;
  struct timespec ts;
  struct timespec rem;

  ts.tv_sec = ms / 1000;
  ts.tv_nsec = (ms % 1000) * 1000000;
  for (;;)
    {
      rv = nanosleep (&ts, &rem);
      if (!rv)
	{
	  break;
	}
      assert (errno == EINTR);
      ts = rem;
    }
}

void *
my_thread (void *context)
{
  int i;
  int n;
  int si;
  int rv;
  void *p;

  n = (int) (intptr_t) context;

  while (!go)
    {
      my_sleep (100);
    }

  // first we spin to get our own arena
  while (spin)
    {
      p = malloc (ALLOCSIZE);
      assert (p);
      if (rand () % 20000 == 0)
	{
	  my_sleep (10);
	}
      free (p);
    }

  my_sleep (1000);

  // then one thread at a time, do our big allocs
  rv = pthread_mutex_lock (&mutex);
  assert (!rv);
  for (i = 0; i < nallocs; i++)
    {
      assert (i < nps);
      ps[i] = malloc (ALLOCSIZE);
      assert (ps[i]);
    }
  // N.B. we leave 1 of every STRAGGLERS allocations straggling
  for (i = 0; i < nallocs; i++)
    {
      assert (i < nps);
      if (i % STRAGGLERS == 0)
	{
	  si = nallocs / STRAGGLERS * n + i / STRAGGLERS;
	  assert (si < nss);
	  ss[si] = ps[i];
	}
      else
	{
	  free (ps[i]);
	}
    }
  done++;
  printf ("%d ", done);
  fflush (stdout);
  rv = pthread_mutex_unlock (&mutex);
  assert (!rv);
}

int
main (int argc, char **argv)
{
  int i;
  int rv;
  time_t n;
  time_t t;
  time_t lt;
  pthread_t thread;
  char command[128];


  if (argc > 1)
    {
      if (!strcmp (argv[1], "-x"))
	{
	  spin = 1;
	  argc--;
	  argv++;
	}
    }
  if (argc > 1)
    {
      printf ("usage: memx2 [-x]\n");
      return 1;
    }

  cpus = sysconf (_SC_NPROCESSORS_CONF);
  pages = sysconf (_SC_PHYS_PAGES);
  pagesize = sysconf (_SC_PAGESIZE);
  printf ("cpus = %d; pages = %d; pagesize = %d\n", cpus, pages, pagesize);

  nallocs = pages / 10 / STRAGGLERS * STRAGGLERS;
  assert (!(nallocs % STRAGGLERS));
  printf ("nallocs = %d\n", nallocs);

  nps = nallocs;
  ps = malloc (nps * sizeof (*ps));
  assert (ps);
  nss = NTHREADS * nallocs / STRAGGLERS;
  ss = malloc (nss * sizeof (*ss));
  assert (ss);

  if (pagesize != 4096)
    {
      printf ("WARNING -- this program expects 4096 byte pagesize!\n");
    }

  printf ("--- creating %d threads ---\n", NTHREADS);
  for (i = 0; i < NTHREADS; i++)
    {
      rv = pthread_create (&thread, NULL, my_thread, (void *) (intptr_t) i);
      assert (!rv);
      rv = pthread_detach (thread);
      assert (!rv);
    }
  go = 1;

  if (spin)
    {
      printf ("--- allowing threads to create preferred arenas ---\n");
      my_sleep (5000);
      spin = 0;
    }

  printf ("--- waiting for threads to allocate memory ---\n");
  while (done != NTHREADS)
    {
      my_sleep (1000);
    }
  printf ("\n");

  printf ("--- malloc_stats() ---\n");
  malloc_stats ();
  sprintf (command, "cat /proc/%d/status | grep -i vm", (int) getpid ());
  printf ("--- %s ---\n", command);
  (void) system (command);

  // access the stragglers
  printf ("--- accessing memory ---\n");
  t = time (NULL);
  lt = t;
  for (i = 0; i < nss; i++)
    {
      memset (ss[i], 0, ALLOCSIZE);
      n = time (NULL);
      if (n - lt >= 60)
	{
	  printf ("%d secs... ", (int) (n - t));
	  fflush (stdout);
	  lt = n;
	}
    }
  if (lt != t)
    {
      printf ("\n");
    }
  printf ("--- done in %d seconds ---\n", (int) (time (NULL) - t));

  return 0;
}
