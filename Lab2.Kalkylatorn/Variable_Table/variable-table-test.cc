/*
 * variable-table-test.cc
 */

#include "variable_table.h"
#include <iostream>

using namespace std;

int main()
{
  Variable_Table v_t;
  //  Variable_Table v_t2 {v_t}; Kopieringskonstruktor deletad.

  cout << "\nSkapar en variabeltabell med defaultkonstruktor.\n\n";

  if( v_t.empty() )
    {
      cout << "Variabeltabellen är tom.\n\n";
    }
  else
    {
      cout << "Variabeltabellen innehåller:\n";
      v_t.list(cout);
    }

  cout << "Skapar och sätter in några variabler med värden.\n\n";

  v_t.insert("x", 53.2);
  v_t.insert("y", 2);
  v_t.insert("hej mamma", 924);

  if( v_t.empty() )
    {
      cout << "Variabeltabellen är tom.\n\n";
    }
  else
    {
      cout << "Variabeltabellen innehåller:\n";
      v_t.list(cout);
    }

  string a {"x"};
  string b {"y"};

  if( v_t.find(a) )
    {
      cout << "\n" << a << " finns i variabeltabellen och har värdet: "
	   << v_t.get_value(a) << "\n\n";
    }
  else
    {
      cout << a << " finns INTE i variabeltabellen.\n\n";
    }

  double temp;

  cout << "Ändra värde på " << a << " till:\n"
       << ">> ";
  cin >> temp;

  v_t.set_value(a, temp);

  cout << "\nTar bort variabel " << b << " från variabeltabellen.\n\n";

  v_t.remove(b);

  if( v_t.empty() )
    {
      cout << "Variabeltabellen är tom.\n\n";
    }
  else
    {
      cout << "Variabeltabellen innehåller:\n";
      v_t.list(cout);
    }

  cout << "\nRensar variabeltabellen.\n\n";

  v_t.clear();

  if( v_t.empty() )
    {
      cout << "Variabeltabellen är tom.\n\n";
    }
  else
    {
      cout << "Variabeltabellen innehåller:\n\n";
      v_t.list(cout);
    }


  return 0;

}
