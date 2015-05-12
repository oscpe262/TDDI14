/*
 * expression_tree-test.cc
 *
 * Program för att testa Expression_Tree-klasserna. Lägg till fler test vid behov!
 */
#include "Expression_Tree.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
   // Ska inte vara möjligt - Expression_Tree ska vara abstrakt:
   // Expression_Tree* t0{ new Expression_Tree };

  Expression_Tree* t1{ new Assign( new Variable("hej"), new Plus( new Real(2.1), new Times( new Real(3), new Real(4.5) ) ) ) };
   
   try
   {
      cout << "t1->evaluate() = " << t1->evaluate() << '\n';
   }
   catch (const exception& e)
   {
      cout << "Undantag fångat: " << e.what() << '\n';
      return 1;
   }

   cout << "t1->get_postfix() = " << t1->get_postfix() << '\n';
   cout << "t1->str() = " << t1->str() << "\n\n";

   
   Expression_Tree* t2{ t1->clone() };

   try
   {
      cout << "t2->evaluate() = " << t2->evaluate() << '\n';
   }
   catch (const exception& e)
   {
      cout << "Undantag fångat: " << e.what() << '\n';
      return 2;
   }
   
   cout << "t2->get_postfix() = " << t2->get_postfix() << '\n';
   cout << "t2->str() = " << t2->str() << "\n\n";
   
   t1->print(cout);

   cout << &t1 << endl << &t2 << endl;

   delete t1;
   delete t2;
   return 0;
   
}
