#
# Makefile
#
CCC      = g++
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra
LDFLAGS += -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

all: array-test matrix-test

array-test: array-test.cc Array.h Array.tcc
	$(CCC) $(CCFLAGS) $(LDFLAGS) -o array-test array-test.cc 

matrix-test: matrix-test.cc Array.h Array.tcc
	$(CCC) $(CCFLAGS) $(LDFLAGS) -o matrix-test matrix-test.cc 

clean:
	@\rm -f *.o

zap: clean
	@\rm -rf array-test matrix-test *~
