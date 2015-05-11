/*
 * uppgift2-2.cc    TDDI14 2014-05-28
 */
#include <iostream>
using namespace std;

enum Step { One = 1, Two, Three };

Step& operator++(Step& s)
{
   switch (s) 
   {
      case One:
	 s = Two;
	 break;
      case Two:
	 s = Three;
	 break;
      case Three:
	 break;
      default:
	 break;
   }
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
   switch (s) 
   {
      case One:
	 break;
      case Two:
	 s = One;
	 break;
      case Three:
	 s = Two;
	 break;
      default:
	 break;
   }
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
