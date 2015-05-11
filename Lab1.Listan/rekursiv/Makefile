#
# Makefil för Laboration Listan
#
# Observera, LDFLAGS är en fix för att lösa problem med länkbiblioteken på
# IDA:s Solarissystem. Inte nödvändigtvis ett problem för denna laboration.
#
#CCC      = g++
CCC      = gccfilter -a -c g++
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra
LDFLAGS += -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

list-test: List.h List.cc list-test.cc Makefile
	$(CCC) $(CCFLAGS) $(LDFLAGS) -o list-test list-test.cc List.cc
	@echo "Kör programmet med kommandot ./list-test"

# Städa
clean: 
	@ \rm -f *.o *.gch core

# Storstäda
zap: clean
	@ \rm -rf list-test *~
