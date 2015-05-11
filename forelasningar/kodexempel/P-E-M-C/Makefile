#
# Simple Makefile for Person-Employee-Manager-Consultant example
#
# Add option -g to CCFLAGS to compile for debugger.
#
# LDFLAGS fixes link library problems with the IDA installation of GCC 4.6 or 
# later for Solaris.
#
# GCC4_V is an environment variable is set by module prog/gcc/4 to the
# corresponding GCC version (typically the latest available at IDA).
#
CCC      = gccfilter -c -a g++
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra
LDFLAGS += -L/sw/gcc-$(GCC4_V)/lib -static-libstdc++

pemc-test: pemc-test.o Date.o CRN.o Person.o Employee.o Manager.o Consultant.o
	$(CCC) $(CCFLAGS) $(LDFLAGS) -o pemc-test pemc-test.o Date.o CRN.o \
		Person.o Employee.o Manager.o Consultant.o

pemc-test.o: Date.h CRN.h Person.h Employee.h Manager.h Consultant.h pemc-test.cc
	$(CCC) $(CCFLAGS) -c pemc-test.cc

Date.o: Date.h Date.cc
	$(CCC) $(CCFLAGS) -c Date.cc

CRN.o: CRN.h CRN.cc
	$(CCC) $(CCFLAGS) -c CRN.cc

Person.o: Date.h CRN.h Person.h Person.cc
	$(CCC) $(CCFLAGS) -c Person.cc

Employee.o: Date.h CRN.h Person.h Employee.h Employee.cc
	$(CCC) $(CCFLAGS) -c Employee.cc

Manager.o: Date.h CRN.h Person.h Employee.h Manager.h Manager.cc
	$(CCC) $(CCFLAGS) -c Manager.cc

Consultant.o: Date.h CRN.h Person.h Employee.h Consultant.h Consultant.cc
	$(CCC) $(CCFLAGS) -c Consultant.cc

clean:
	@ \rm -f *.o *.gch core

zap: clean
	@ \rm -f pemc-test *~
