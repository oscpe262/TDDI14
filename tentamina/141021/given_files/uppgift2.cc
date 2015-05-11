/*
 * uppgift2.cc
 */
#include <iostream>
using namespace std;

class Adder
{
public:
   Adder(int i = 0) : value_{ i } {}

private:
   int value_;
};

int main()
{
   Adder a1;

/*
   cout << a1 << '\n';          // 0

   a1 += 5;
   cout << a1 << '\n';          // 5

   a1 = 11;
   cout << a1 << '\n';          // 11

   Adder a2{ 10 };
   cout << a2 << '\n';          // 10

   cout << (a1 + a2) << '\n';   // 21

   Adder a3{ a2 };
   cout << a3 << '\n';          // 10

   a3 = a1;
   cout << a1 << '\n';          // 11

   a3 += a1;
   cout << a3 << '\n';          // 22
*/
   return 0;
}
