/*
 * kalkylator.cc
 *
 * Ett objekt av typen Calculator skapas i main() och Calculator::run()
 * körs. Om ett undantag kastas av Calculator::run() fångas detta och 
 * programmet avslutas sedan efter att ett felmeddelande skrivits ut.
 */
#include "Calculator.h"
#include <iostream>
using namespace std;

int main()
{
   Calculator calc;

   try
   {
      calc.run();
   }
   catch (const exception& e) // ska inte kunna hända här egentligen
   {
      cout << e.what() << '\n';
   }
   catch (...) // "catch all"
   {
      cout << "Ett okänt fel har inträffat.\n";
   }

   return 0;
}
