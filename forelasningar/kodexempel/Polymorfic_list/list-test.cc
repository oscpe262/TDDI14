/*
 * list-test.cc
 */
#include "List.h"
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main()
{
   List list_1;  // defaultkonstruktor

   if (list_1.empty()) cout << "list_1 �r tom.\n\n";

   // insert
   cout << "S�tter in 3, 1, 5, 4, 2 i list_1.\n";
   list_1.insert(3);
   list_1.insert(1);
   list_1.insert(5);
   list_1.insert(4);
   list_1.insert(2);

   if (!list_1.empty()) cout << "list_1 �r inte tom.\n";

   cout << "list_1: ";
   list_1.print(cout);
   cout << '\n';
   if (!list_1.empty()) cout << "list_1 �r inte tom.\n";
   cout << "list_1 har l�ngd " << list_1.length() << '\n';
   if (list_1.member(2)) cout << "list_1 inneh�ller 2\n";
   if (! list_1.member(0)) cout << "list_1 inneh�ller inte 0\n";
   cout << '\n';

   cout << "Kopieringskonstruerar list_2 fr�n list_1.\n";
   List list_2(list_1);  // kopieringskonstruktor
   cout << "list_2: ";
   list_2.print(cout, " ");
   cout << '\n';
   cout << "list_1: ";
   list_1.print(cout, " ");
   cout << "\n\n";

   // remove
   cout << "Tar bort 3 ur list_1\n";
   list_1.remove(3);  // mitt i
   cout << "Tar bort 1 ur list_1\n";
   list_1.remove(1);  // f�rst
   cout << "Tar bort 5 ur list_1\n";
   list_1.remove(5);  // sist
   cout << "list_1: ";
   list_1.print(cout, " ");
   cout << '\n';
   cout << "list_2: ";
   list_2.print(cout, " ");
   cout << "\n\n";

   cout << "Byter inneh�ll p� list_1 och list_2 med medlemmen swap.\n";
   list_1.swap(list_2);
   cout << "list_1: ";
   list_1.print(cout, " ");
   cout << '\n';
   cout << "list_2: ";
   list_2.print(cout, " ");
   cout << "\n\n";

   cout << "Byter inneh�ll p� list_1 och list_2 med frist�ende swap.\n";
   swap(list_1, list_2);
   cout << "list_1: ";
   list_1.print(cout, " ");
   cout << '\n';
   cout << "list_2: ";
   list_2.print(cout, " ");
   cout << "\n\n";

   cout << "Move-konstruerar ny lista list_3 fr�n list_1.\n";
   List list_3(std::move(list_1));  // move-konstruktor
   cout << "list_3: ";
   list_3.print(cout, " ");
   cout << '\n';
   if (list_1.empty()) cout << "list_1 �r tom.\n";
   cout << '\n';

   cout << "Raderar list_3." << '\n';
   list_3.clear();
   if (list_3.empty()) cout << "list_3 �r tom.\n\n";

   cout << "Kopieringstilldelar list_3 fr�n list_2." << '\n';
   list_3 = list_2;  // kopieringstilldelningsoperator
   cout << "list_3: ";
   list_3.print(cout, " ");
   cout << '\n';
   cout << "list_2: ";
   list_2.print(cout, " ");
   cout << "\n\n";

   if (list_1.empty()) cout << "list_1 �r tom.\n";
   cout << "Move-tilldelar list_1 fr�n list_2." << '\n';
   list_1 = std::move(list_2);  // move-tilldelningsoperator
   cout << "list_1: ";
   list_1.print(cout, " ");
   cout << '\n';
   if (list_2.empty()) cout << "list_2 �r tom.\n";

   // destruktor testas implicit...

   return 0;
}
