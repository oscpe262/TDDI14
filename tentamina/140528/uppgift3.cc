/*
 * uppgift3.cc    TDDI14 2014-05-28
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

template<typename T, int Precision = 6> 
class Real
{
public:
   explicit Real(const T& value) : value_{ value } {}

   Real(const Real&) = default;
   ~Real() = default;
   Real& operator=(const Real&) = default;

   string str() const;

private:
   T value_;
};

template<typename T, int Precision> 
string Real<T, Precision>::str() const
{
   ostringstream os;
   os << fixed << setprecision(Precision) << value_;
   return os.str();
}

int main()
{
   Real<double, 8> r1{ 3.14159265 };

   Real<float> r2{ 1.0 };

   string s{ r1.str() };
   cout << s << '\n';            // 3.14159265

   s = r2.str();
   cout << s << "\n\n";          // 1.000000

   Real<double, 8> r3{ r1 };
   cout << r3.str() << '\n';     // 3.14159265

   Real<float> r4{ r2 };
   cout << r4.str() << "\n\n";   // 1.000000

   r1 = r3;
   r2 = r4;

   cout << r1.str() << '\n';
   cout << r2.str() << '\n';
   cout << r3.str() << '\n';
   cout << r4.str() << '\n';

   return 0;
}
