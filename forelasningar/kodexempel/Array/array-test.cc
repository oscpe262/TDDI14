/*
 * array_test.cc
 */
#include "Array.h"
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <stdexcept>
using std::cout;
using std::endl;
using std::exception;

template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const Array<T, N>& a);

int main()
{
   Array<double, 10> arr1;

   cout << "arr1 har storleken " << arr1.size() << '\n';

   for (size_t i = 0; i < arr1.size(); ++i) 
   {
      arr1[i] = 3.1415 * (i + 1);
   }

   cout << "arr1 innehåller:\n" << arr1 << '\n';

   Array<int, 100> arr2;

   cout << "\narr2 har storleken " << arr2.size() << '\n';

   try 
   {
      cout << "Provar 'arr2[666]': ";
      cout << arr2[666] << '\n';
   }
   catch (const exception& e) {
      cout << "undantag fångat: " << e.what() << '\n';
   }

   try 
   {
      cout << "Provar 'arr2.at(666)': ";
      cout << arr2.at(666) << '\n';
   }
   catch (const exception& e) {
      cout << "undantag fångat: " << e.what() << '\n';
   }

   cout << "\nInitierar ny arr3 med kopieringskonstruktorn och arr1 som argument.\n";
   Array<double, 10> arr3(arr1);

   cout << "arr3 har storleken " << arr3.size() << '\n';

   cout << "arr3 innehåller:\n" << arr3 << '\n';

   cout << boolalpha << "\nTestet '(arr1 == arr3' ger: " << (arr1 == arr3) << '\n';
   cout << "Testet '(arr1 < arr3' ger: " << (arr1 < arr3) << '\n';

   arr3 = arr1;

   cout << "\nEfter tilldelning 'arr3 = arr1':\n" << arr3 << '\n';

   return 0;
}

template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const Array<T, N>& a)
{
   for (std::size_t i = 0; i < a.size(); ++i)
      os << a[i] << ' ';
   return os;
}
