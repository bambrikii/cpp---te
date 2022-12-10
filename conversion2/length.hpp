// Convert between inches and cm
#define INCHES_PER_METER 39.3700787

#if !defined(LENGTH)
#define LENGTH "LENGTH"
class length {
private:
	double d;
public:
	double cm();
	void cm(double x);
	double inches();
	void inches(double x);
};

#endif
