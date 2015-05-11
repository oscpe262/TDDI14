#
# Makefile
#

#CCC      = g++
CCC      = gccfilter -a -c g++
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra
LDFLAGS += -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

all: list-test

list-test: list-test.o List.h List.o Makefile
	${CCC} $(CCFLAGS) $(LDFLAGS) -o list-test list-test.o List.o

list-test.o: list-test.cc
	${CCC} $(CCFLAGS) -c list-test.cc

List.o: List.h List.cc
	${CCC} $(CCFLAGS) -c List.cc

clean:
	@\rm -f *.o *.gch core

zap: clean
	@\rm -rf list-test iterator-test *~
