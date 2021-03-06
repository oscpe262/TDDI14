#
# Makefile f�r kalkylatorn
#
# Filkatalog d�r andra delar av programet finns.
EXPRESSION = ../Expression
VARIABLE_TABLE = ../Variable_Table

# Kompilator (gcc) och diagnostikfilter (gccfilter)
CCC = gccfilter -a -c g++

# Kompilatorflaggor, l�gg till '-g' om kompilering f�r avlusning ska g�ras.
CCFLAGS += -std=c++11 -Wpedantic -Wall -Wextra

# L�nkflaggor f�r att fixa problem med nuvarande versioner av Solaris och 
# C++ l�nkbibliotek.
LDFLAGS += -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

# Preprocessorflaggor, -I l�gger till en filkatalog i inkluderingss�kv�gen.
CPPFLAGS += -I$(EXPRESSION) -I$(VARIABLE_TABLE)

# Objektkodsmoduler som ing�r i den kompletta kalkylatorn.
OBJECTS = kalkylator.o Calculator.o Expression.o Expression_Tree.o variable_table.o

# Huvudm�l - skapas med kommandot 'make' eller 'make kalkylator'.
kalkylator: $(OBJECTS) Makefile
	$(CCC) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o kalkylator $(OBJECTS)

# Delm�l (flaggan -c avbryter innan l�nkning)
kalkylator.o: Calculator.h kalkylator.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c kalkylator.cc

Calculator.o: $(EXPRESSION)/Expression.h Calculator.h Calculator.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Calculator.cc

Expression.o: $(EXPRESSION)/Expression_Tree.h $(EXPRESSION)/Expression.h $(EXPRESSION)/Expression.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c $(EXPRESSION)/Expression.cc

Expression_Tree.o: $(EXPRESSION)/Expression_Tree.h $(EXPRESSION)/Expression_Tree.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c $(EXPRESSION)/Expression_Tree.cc

variable_table.o: $(VARIABLE_TABLE)/variable_table.h $(VARIABLE_TABLE)/variable_table.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c $(VARIABLE_TABLE)/variable_table.cc


# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o *.gch core

# 'make zap' tar �ven bort det k�rbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf kalkylator *~

# '@' medf�r att kommandot inte skrivs ut p� sk�rmen d� det utf�rs av make.
# 'rm' �r ett alias f�r 'rm -i' p� IDA:s system, '\rm' inneb�r att "original-
# versionen", utan skyddsn�tet '-i', anv�nds. Se upp vid �ndring, '*' f�r 
# absolut inte finnas f�r sig!
