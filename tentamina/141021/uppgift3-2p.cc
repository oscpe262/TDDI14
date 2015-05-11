/*
 * uppgift3-2p.cc    Tentamen 2014-10-21
 */
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
using namespace std;

template<typename T1, typename T2>
void
print_pair(ostream& os, const pair<T1, T2>& p)
{
   os << p.first << ';' << p.second;
}

template<typename T1, typename T2>
void
read_pair(istream& is, pair<T1, T2>& p)
{
   char delimiter;
   is >> p.first >> delimiter >> p.second;
}

int main()
{
   pair<char, int> p1('A', 1);
   print_pair(cout, p1);
   cout << '\n';

   cout << "Mata in ett par på formen char;int: ";
   read_pair(cin, p1);
   print_pair(cout, p1);
   cout << "\n\n";

   cout << boolalpha;
   cin >> boolalpha;

   pair<bool, bool> p2(false, true);
   print_pair(cout, p2);
   cout << '\n';

   cout << "Mata in ett par på formen bool;bool: ";
   read_pair(cin, p2);
   print_pair(cout, p2);
   cout << "\n\n";

   return 0;
}
