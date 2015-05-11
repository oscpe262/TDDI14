/*
 * expression-test.cc
 *
 * Program för att testa klassen Expression. Lägg till fler test!
 */
#include "Expression.h"
#include "Expression_Tree.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
   Expression e1;  // Defaultkonstruktor

   if (e1.empty())
      cout << "Tomt uttryck!\n";
   else
      cout << "e1.evaluate() = " << e1.evaluate() << '\n';

   cout << "e1.get_postfix() = " << e1.get_postfix() << '\n';
   cout << boolalpha << "e1.empty() = " << e1.empty() << "\n\n";

   Expression { e1 };  // Kopieringskonstruktor

   try
   {
      cout << "e2.evaluate() = " << e2.evaluate() << '\n';
   }
   catch (const exception& e)
   {
      cout << "Undantag fångat: " << e.what() << '\n';
   }

   cout << "e2.get_postfix() = " << e2.get_postfix() << '\n';
   cout << "e2.empty() = " << e2.empty() << "\n\n";
   
   e2.swap(e1);

   // Nedanstående kräver implementering av Expression_Tree-klasserna.

/*
   Expression_Tree* t{ new Plus(new Integer(7), new Real(3.14) };

   Expression e3{ t };  // Konstruktor som tar ett länkat uttrycksträd

   cout << "e3.evaluate() = " << e3.evaluate() << '\n';
   cout << "e3.get_postfix() = " << e3.get_postfix() << '\n';
   cout << "e3.empty() = " << e3.empty() << "\n\n";

   e2.swap(e3);

   cout << "e2.evaluate() = " << e2.evaluate() << '\n';
   cout << "e2.get_postfix() = " << e2.get_postfix() << '\n';
   cout << "e2.empty() = " << e2.empty() << "\n\n";

   Expression e4{ e3 };

   try
   {
      cout << "e4.evaluate() = " << e4.evaluate() << '\n';
   }
   catch (const exception& e)
   {
      cout << "Undantag fångat: " << e.what() << '\n';
   }
   cout << "e4.get_postfix() = " << e4.get_postfix() << '\n';
   cout << "e4.empty() = " << e4.empty() << "\n\n";
*/

   return 0;
}
