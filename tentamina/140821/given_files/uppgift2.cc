/*
 * uppgift2.cc
 */
#include <iostream>
#include <iomanip>
// Fler inkluderingar efter behov
using namespace std;

// Definiera Round_Robin och round_robin_error h�r.

int main()
{
   Round_Robin<int, 10>   rr1;
   Round_Robin<long, 100> rr2;

   for (int x : { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 })
   {
      // Placera undantagshanterare som f�ngar alla slag undantag i exception-
      // hierarkin som eventuellt kastas i detta block, skriver ut det meddelande
      // som s�dana undantag b�r med sig och avbryter for-satsen och l�ter
      // programmet forts�tta med den kod som f�ljer efter denna fir-sats.

      rr1.add(x);
	 
      for (int i = 0; i < rr1.size(); ++i) 
      {
	 cout << *rr1 << ' ';
	 ++rr1;
      }
      cout << '\n';
	 
      rr2.add(x);
   }
   
   for (int i = 0; i < rr2.size(); ++i) 
   {
      cout << *rr2++ << ' ';
      ++rr2;
   }
   cout << *rr2 << '\n';

   return 0;
}
