/*
 * list_test.cc    Laboration Listan
 */
#include "List.h"
#include <iostream>
using namespace std;

void print(ostream& os, const List& lst)
{
   lst.print(cout, " -> ");
   os << '\n';
}

int main()
{
   List  list_1;
   cout << "Ny lista skapad\n";

   if (list_1.empty())
      cout << "Listan är tom\n";
   else
      cout << "Listan är inte tom\n";

   cout << "\nSätter in, i tur och ordning, 1, 2, 3 först i listan\n";
   list_1.insert(1);
   list_1.insert(2);
   list_1.insert(3);

   if (list_1.empty())
      cout << "Listan är tom\n";
   else
      cout << "Listan är inte tom\n";

   cout << "Listan innehåller: ";
   print(cout, list_1);

   cout << "\nSätter in, i tur och ordning, 4, 5, 6 sist i listan\n";
   list_1.append(4);
   list_1.append(5);
   list_1.append(6);

   cout << "Listan innehåller: ";
   print(cout, list_1);

   if (list_1.member(4))
      cout << "\nVärdet 4 finns i listan\n";
   else
      cout << "\nVärdet 4 finns ej i listan\n";

   if (list_1.member(7))
      cout << "Värdet 7 finns i listan\n";
   else
      cout << "Värdet 7 finns ej i listan\n";

   cout << "\nTar bort 4 ur listan\n";
   list_1.remove(4);
   
   cout << "Listan innehåller: ";
   print(cout, list_1);

   cout << "\nTar bort 1 ur listan\n";
   list_1.remove(1);
   
   cout << "Listan innehåller: ";
   print(cout, list_1);

   cout << "\nTar bort 6 ur listan\n";
   list_1.remove(6);
   
   cout << "Listan innehåller: ";
   print(cout, list_1);

   cout << "\nTömmer listan\n";
   list_1.clear();

   if (list_1.empty())
   {
      cout << "Listan är tom\n";
   }
   else
   {
      cout << "Listan är inte tom\n";
      cout << "Listan innehåller: ";
      print(cout, list_1);
   }

   cout << "\nSätter in, i tur och ordning, 1, 2, 3 först i listan\n";
   list_1.insert(1);
   list_1.insert(2);
   list_1.insert(3);

   cout << "Listan innehåller: ";
   print(cout, list_1);

   cout << "\nListan destrueras\n";

   return 0;
}
