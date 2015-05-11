/*
 * list-test.cc    Laboration Listan
 */
#include "List.h"
#include <iostream>
#include <iterator>
using namespace std;
using namespace linked_list;

template<typename T>
void print(ostream& os, const linked_list::List<T>& lst)
{
   lst.print(cout, " -> ");
   os << '\n';
}

int main()
{
  linked_list::List<int>  list_1;
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
   copy( list_1.cbegin(), list_1.cend(), ostream_iterator<int>{cout, " "});
   
   cout << "\nSätter in, i tur och ordning, 4, 5, 6 sist i listan\n";
   list_1.append(4);
   list_1.append(5);
   list_1.append(6);

   cout << "Listan innehåller: ";
   for (List<int>::const_iterator it = list_1.cbegin() ; it != list_1.cend() ; ++it){
     cout << *it << " ";
   }
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
   copy(list_1.cbegin(), list_1.cend(), ostream_iterator<int>(cout, " "));

   cout << "\nTar bort 1 ur listan\n";
   list_1.remove(1);
   
   cout << "Listan innehåller: ";
   copy(list_1.cbegin(), list_1.cend(), ostream_iterator<int>(cout, " "));

   cout << "\nTar bort 6 ur listan\n";
   list_1.remove(6);
   
   cout << "Listan innehåller: ";
   copy(list_1.cbegin(), list_1.cend(), ostream_iterator<int>(cout, " "));

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
   copy(list_1.cbegin(), list_1.cend(), ostream_iterator<int>(cout, " "));
   }

   cout << "\nSätter in, i tur och ordning, 1, 2, 3 först i listan\n";
   list_1.insert(1);
   list_1.insert(2);
   list_1.insert(3);

   cout << "Listan innehåller: ";
   for (auto value : list_1 ) {
     cout << value << " ";
   }

   /*
   cout << "\nÖkar respektive elements värden med 1\n";
   for (List<int>::const_iterator it = list_1.cbegin() ; it != list_1.cend() ; ++it){
     cout << ++(*it) << " ";
   }
   */
   cout << "\nListan destrueras\n";

   return 0;
}
