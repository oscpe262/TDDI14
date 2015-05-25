# Kompilator (gcc) och diagnostikfilter (gccfilter)
CCC = g++
# CCC = gccfilter -a -c g++

# Kompilatorflaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -std=c++11 -Wpedantic -Wall -Wextra

# Länkflaggor för att fixa problem med nuvarande versioner av Solaris och 
# C++ länkbibliotek.
LDFLAGS += -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

# Objektkodsmoduler som ingår i testprogrammet.
OBJECTS = variable_table.o variable-table-test.o

# Huvudmål - skapas med kommandot 'make'.
variable-table-test:  $(OBJECTS) Makefile
	$(CCC) $(CCFLAGS) $(LDFLAGS) -o variable-table-test $(OBJECTS)

# Delmål (flaggan -c avbryter innan länkning)
variable-table-test.o: variable_table.h variable-table-test.cc
	$(CCC) $(CCFLAGS) $(LDFLAGS) -c variable-table-test.cc

variable_table.o: variable_table.h variable_table.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c variable_table.cc


# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o *.gch core

# 'make zap' tar även bort det körbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf variable-table-test *~

# '@' medför att kommandot inte skrivs ut på skärmen då det utförs av make.
# 'rm' är ett alias för 'rm -i' på IDA:s system, '\rm' innebär att "original-
# versionen", utan skyddsnätet '-i', används. Se upp vid ändring, '*' får 
# absolut inte finnas för sig!
