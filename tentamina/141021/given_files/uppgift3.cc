/*
 * uppgift3.cc
 */
#include <iostream>
#include <utility>
using namespace std;

// Definiera funktionsmallarna print_pair och read_pair här.

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

   /* För 4 poäng:
   pair<string, string> p3("foo", "bar");
   print_pair(cout, p3);
   cout << '\n';

   cout << "Mata in ett par på formen sträng;sträng: ";
   read_pair(cin, p3);
   print_pair(cout, p3);
   cout << "\n\n";
   */

   return 0;
}
