/*
 * kalkylator.cc
 *
 * Ett objekt av typen Calculator skapas i main() och Calculator::run()
 * k�rs. Om ett undantag kastas av Calculator::run() f�ngas detta och 
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
   catch (const exception& e) // ska inte kunna h�nda h�r egentligen
   {
      cout << e.what() << '\n';
   }
   catch (...) // "catch all"
   {
      cout << "Ett ok�nt fel har intr�ffat.\n";
   }

   return 0;
}
