/*
 * uppgift2-1.cc    TDDI14 2014-05-28
 */
#include <iostream>
using namespace std;

enum Step { One = 1, Two, Three };

Step& operator++(Step& s)
{
   if (s < Three)
      s = static_cast<Step>(s + 1);
   return s;
}

Step operator++(Step& s, int)
{
   Step tmp{ s };
   ++s;
   return tmp;
}

Step& operator--(Step& s)
{
   if (s > One)
      s = static_cast<Step>(s - 1);
   return s;
}

Step operator--(Step& s, int)
{
   Step tmp{ s };
   --s;
   return tmp;
}

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
