/*
 * uppgift3.cc
 */
#include <iostream>
#include <utility>
using namespace std;

// Definiera funktionsmallarna print_pair och read_pair h�r.

int main()
{
   pair<char, int> p1('A', 1);
   print_pair(cout, p1);
   cout << '\n';

   cout << "Mata in ett par p� formen char;int: ";
   read_pair(cin, p1);
   print_pair(cout, p1);
   cout << "\n\n";

   cout << boolalpha;
   cin >> boolalpha;

   pair<bool, bool> p2(false, true);
   print_pair(cout, p2);
   cout << '\n';

   cout << "Mata in ett par p� formen bool;bool: ";
   read_pair(cin, p2);
   print_pair(cout, p2);
   cout << "\n\n";

   /* F�r 4 po�ng:
   pair<string, string> p3("foo", "bar");
   print_pair(cout, p3);
   cout << '\n';

   cout << "Mata in ett par p� formen str�ng;str�ng: ";
   read_pair(cin, p3);
   print_pair(cout, p3);
   cout << "\n\n";
   */

   return 0;
}
