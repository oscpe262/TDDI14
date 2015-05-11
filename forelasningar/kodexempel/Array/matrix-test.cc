/*
 * matrix_test.cc
 */
#include "Array.h"
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <stdexcept>
using namespace std;

int main()
{
   const int  ROWS = 20;
   const int  COLS = 10;

   Array<Array<double, COLS>, ROWS>  m;

   cout << "Antal rader...: " << m.size() << endl;
   cout << "Antal kolumner: " << m[0].size() << endl << endl;

   for (size_t r = 0; r < m.size(); ++r) {
      for (size_t c = 0; c < m[0].size(); ++c) {
	 m[r][c] = 3.1415 * (r + c + 1);
      }
   }

   cout << fixed << setprecision(2);

   for (size_t r = 0; r < m.size(); ++r) {
      for (size_t c = 0; c < m[0].size(); ++c) {
	 cout << setw(5) << m[r][c] << "  ";
      }
      cout << endl;
   }

   Array<Array<double, COLS>, ROWS>  m2;

   cout << "Antal rader...: " << m2.size() << endl;
   cout << "Antal kolumner: " << m2[0].size() << endl << endl;

   for (size_t r = 0; r < m2.size(); ++r) {
      for (size_t c = 0; c < m2[0].size(); ++c) {
	 m2[r][c] = 3.1415 * (r + c + 1);
      }
   }

   cout << fixed << setprecision(2);

   for (size_t r = 0; r < m2.size(); ++r) {
      for (size_t c = 0; c < m2[0].size(); ++c) {
	 cout << setw(6) << m2[r][c] << "  ";
      }
      cout << endl;
   }

   return 0;
}
