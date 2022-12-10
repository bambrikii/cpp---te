conversion: conversion.o length.o
	g++ -o conversion conversion.o length.o

conversion.o: conversion.cpp length.hpp
	g++ -c conversion.cpp

length.o: length.cpp length.hpp
	g++ -c length.cpp

clean:
	rm conversion.o length.o conversion