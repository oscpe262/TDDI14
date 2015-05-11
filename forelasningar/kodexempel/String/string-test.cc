/*
 * string-test.cc
 */
#include <iostream>
#include "String.h"
using namespace std;
using IDA_String::String;

int main()
{
   String s1;  // defaultkonstruktor
   cout << "s1: " << s1 << endl;

   String s2{ "FOO" };  // omvandlande konstruktor, C-sträng till String
   cout << "s2: " << s2 << endl;

   String s3{ s2 };  // kopieringskonstruktor
   cout << "s3: " << s3 << endl;

   String s4{ 'C', '+', '+' };
   cout << "s4: " << s4 << endl;

   String s5(3, 'W');  // konstruktor för 3 stycken 'W'; Obs, inte {} här!
   cout << "s5: " << s5 << endl;

   String s6{std::move(s5)};  // move-konstruktor
   cout << "s6: " << s6 << endl;
   cout << "s5: " << s5 << endl;

   s5 = std::move(s6);  // move-tilldelningsoperator
   cout << "s5: " << s5 << endl;
   cout << "s6: " << s6 << endl;

   s3 = "FIE";  // omvandlande tilldelningsoperator, C-string till String
   cout << "s3: " << s3 << endl;

   // relationsoperatorer
   if (s2 < s3)
      cout << "s2 < s3" << endl;
   else if (s2 > s3)
      cout << "s2 > s3" << endl;
   else
      cout << "s2 == s3" << endl;

   s3 = s2;  // kopieringstilldelningsoperator
   cout << "s3: " << s3 << endl;

   // likhetsoperatorer
   if (s2 != s3)
      cout << "s2 != s3" << endl;
   else
      cout << "s2 == s3" << endl;

   // tom?
   if (s3.empty())
      cout << "s3 är tom." << endl;
   else
      cout << "s3 är inte tom." << endl;

   // + operatorer
   cout << "s2 + \"L\": " << s2 + "L" << endl;
   cout << "\"L\" + s2: " << "L" + s2 << endl;
   cout << "s2 + s3: " << s2 + s3 << endl;

   // += operatorer
   s2 += "L";
   cout << "Efter s2 += \"L\", s2: " << s2 << endl;
   s3 += s2;
   cout << "Efter s3 += s2, s3: " << s3 << endl;

   // indexeringsoperatorer
   s3[3] = 'L';
   cout << "s3[3] = 'L';" << endl;
   s3[4] = 'S';
   cout << "s3[4] = 'S';" << endl;
   s3[6] = 'M';
   cout << "s3[6] = 'M'; " << endl;
   cout << "s3: " << s3 << endl;
   cout << "s3.at(0): " << s3.at(0) << endl;

   cout << "s3.length(): " << s3.length() << endl;

   s2 = 'X';  // omvandlande tilldelningsoperator, char till String
   cout << "Efter s2 = 'X', s2: " << s2 << endl;
   s2 += 'Y';  // += för char
   cout << "Efter s2 += 'Y', s2: " << s2 << endl;

   cout << "s2 + 'Z': " << s2 + 'Z' << endl;
   cout << "'W' + s2: " << 'W' + s2 << endl;

   // at() för säker indexering
   try
   {
      cout << "s3.at(7): " << s3.at(7) << endl;
   }
   catch (const exception& e)
   {
      cout << e.what() << endl;
   }

   // clear
   cout << "s2.clear();" << endl;
   s2.clear();

   if (s2.empty())
      cout << "s2 är tom." << endl;
   else
      cout << "s2 är inte tom." << endl;

   // typomvandling
   cout << "const char* p = s2.c_str();" << endl;
   const char* p1 = s2.c_str();
   cout << "p1: " << p1 << endl;

   cout << "const char* p2 = static_cast<const char*>(s3);" << endl;
   const char* p2 = static_cast<const char*>(s3);
   cout << "p2: " << p2 << endl;

   // I/O
   String s7;
   cout << "Skriv ett word: ";
   cin >> s7;
   cout << "cin >> s7;" << endl;
   cout << "s7: " << s7 << endl;

   cout << "Skriv en rad: ";
   cin >> ws;
   getline(cin, s7);
   cout << "getline(cin, s7);" << endl;
   cout << "s7: " << s7 << endl;

   cout << "Skriv en rad till (' ' är bryttecken): ";
   cin >> ws;
   getline(cin, s7, ' ');
   cout << "getline(cin, s7, ' ');" << endl;
   cout << "s7: " << s7 << endl;

   return 0;
}
