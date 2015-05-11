#
# Makefile for compiling String with GNU GCC g++
#
# LDFLAGS is a fix for the current GCC installation on IDA's Solaris system.
#
# Add -g to CCFLAGS for debugging (or introduce CPPFLAGS)
#
CCC      = gccfilter -c -a g++
CCFLAGS += -g -std=c++11 -pedantic -Wall -Wextra
LDFLAGS += -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

all: string-test string-conversion-test string-iterator-test

string-test: string-test.o String.o Makefile
	$(CCC) $(CCFLAGS) $(LDFLAGS) -o string-test string-test.o String.o

string-test.o: String.h string-test.cc
	$(CCC) $(CCFLAGS) -c string-test.cc

string-conversion-test: string-conversion-test.o String.o
	$(CCC) $(CCFLAGS) $(LDFLAGS) -o string-conversion-test string-conversion-test.o String.o

string-conversion-test.o: String.h string-conversion-test.cc
	$(CCC) $(CCFLAGS) -c string-conversion-test.cc

string-iterator-test: string-iterator-test.o String.o
	$(CCC) $(CCFLAGS) $(LDFLAGS) -o string-iterator-test string-iterator-test.o String.o

string-iterator-test.o: String.h string-iterator-test.cc
	$(CCC) $(CCFLAGS) -c string-iterator-test.cc

String.o: String.h String.cc
	$(CCC) $(CCFLAGS) -c String.cc

clean:
	@ \rm -f *.o *.gch core

zap: clean
	@ \rm -f *~ string-test string-conversion-test string-iterator-test
