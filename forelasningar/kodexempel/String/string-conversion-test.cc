/*
 * string-conversion-test.cc
 */
#include <iostream>
#include "String.h"
using namespace std;
using namespace IDA_String;

int main()
{
   String s{ "FOO" };
   cout << "s: " << s << endl;

// const char* p1 = s;  // not if 'operator const char*()' is explicit 

   // Using 'operator const char*()' explicit:

   const char* p2 = static_cast<const char*>(s);  // static_cast

   cout << "p2 = " << p2 << endl;

   const char* p3 = (const char*)s;  // cast notation

   cout << "p3 = " << p3 << endl;

   using C_string = const char*;

   const char* p4 = C_string(s);     // functional form

   cout << "p4 = " << p4 << endl;

   return 0;
}
