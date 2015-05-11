# Exempel på makefil
CCC = g++
CFLAGS += -std=c++11 -Wall -pedantic -Wextra -fdiagnostics-color=always

name-test: name-test.o Name.o
	$(CCC) $(CFLAGS) -o name-test name-test.cc Name.cc
	@echo "Exekvera med ./name-test"
name-tes.o: name-test.cc # Kollar uppdateringsstatus, kompilerar vid behov
	$(CCC) $(CFLAGS) -c name-test.cc
name.o: Name.cc
	$(CCC) $(CFLAGS) -c Name.cc
clean:
	rm -f *~ name-test 
