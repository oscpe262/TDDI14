/*
 * iterator-test.cc
 */
#include "String.h"
#include <cctype>
#include <iostream>
using namespace std;
using IDA_String::String;

int main()
{
   String s1;

   cout << "s1 is empty: ";
   for (String::const_iterator it = s1.cbegin(); it != s1.cend(); ++it)
   {
      cout << *it;
   }
   cout << '\n';

   String s2{"Gazonk"};

   cout << "s2: ";
   for (String::const_iterator it = s2.cbegin(); it != s2.cend(); ++it)
   {
      cout << *it;
   }
   cout << '\n';

   for (String::iterator it = s2.begin(); it != s2.end(); ++it)
   {
      *it = toupper(*it);
   }

   cout << "s2 printed backwards, after being uppercased: ";
   for (String::const_reverse_iterator it = s2.crbegin(); it != s2.crend(); ++it)
   {
      cout << *it;
   }
   cout << '\n';

   cout << "s2: ";
   for (auto c : s2)
   {
      cout << c;
   }
   cout << '\n';

   for (auto& c : s2)
   {
      c = tolower(c);
   }

   cout << "s2 after being lowercased: ";
   for (auto c : s2)
   {
      cout << c;
   }
   cout << '\n';

   return 0;
}
