#
# Makefil f�r Laboration Listan
#
# Observera, LDFLAGS �r en fix f�r att l�sa problem med l�nkbiblioteken p�
# IDA:s Solarissystem. Inte n�dv�ndigtvis ett problem f�r denna laboration.
#
CCC      = g++
#CCC      = gccfilter -a -c g++
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra -fdiagnostics-color=always
LDFLAGS += -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

list-test: List.h list-test.cc Makefile
	$(CCC) $(CCFLAGS) $(LDFLAGS) -o list-test list-test.cc
#	$(CCC) $(CCFLAGS) -o list-test list-test.cc
	@echo "K�r programmet med kommandot ./list-test"

# St�da
clean: 
	@ \rm -f *.o *.gch core

# Storst�da
zap: clean
	@ \rm -rf list-test *~
