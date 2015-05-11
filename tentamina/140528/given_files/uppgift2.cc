/*
 * uppgift2.cc
 *
 * Namn, pnr:
 *
 * Varningar skrivs ut om oanvänd variabel 'i' (det stämmer).
 */
#include <iostream>
using namespace std;

enum Step { One, Two, Three };

int main()
{
   Step s{ One };

   for (auto i : { 1, 2, 3, 4 })
   {
      cout << s << ' ';
      ++s;
   }
   cout << "\n\n";

   s = One;
   cout << s++ << '\n';
   cout << s << "\n\n";

   s = One;
   ++++s;
   cout << s << "\n\n";

   for (auto i : { 1, 2, 3, 4 })
   {
      cout << s << ' ';
      --s;
   }
   cout << "\n\n";

   s = Two;
   cout << s-- << '\n';
   cout << s-- << '\n';
   cout << s-- << '\n';

   return 0;
}
