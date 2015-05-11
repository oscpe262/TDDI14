/*
 * uppgift2-1.cc    TDDI14 2014-10-21
 */
#include <iostream>
using namespace std;

template<typename T>
class Adder
{
public:
   Adder(const T& init = T{}) : value_{ init } {}

   Adder(const Adder&) = default;
   Adder(Adder&&) = default;
   ~Adder() = default;
   Adder& operator=(const Adder&) = default;
   Adder& operator=(Adder&&) = default;

   Adder& operator+=(const Adder& rhs)
   { 
      value_ += rhs.value_; 
      return *this;
   }

   explicit operator T() const { return value_; }

private:
   T value_;
};

template<typename T>
Adder<T>
operator+(const Adder<T>& lhs, const Adder<T>& rhs)
{
   return Adder<T>{ lhs }.operator+=(rhs);
}

template<typename T>
ostream& operator<<(ostream& os, const Adder<T>& a)
{
   return os << static_cast<T>(a);
}

int main()
{
   Adder<int> a1;
   cout << a1 << '\n';          // 0

   a1 += 5;
   cout << a1 << '\n';          // 5

   a1 = 11;
   cout << a1 << '\n';          // 11

   Adder<int> a2{ 10 };
   cout << a2 << '\n';          // 10

   cout << (a1 + a2) << '\n';   // 21

   Adder<int> a3{ a2 };
   cout << a3 << '\n';          // 10

   a3 = a1;
   cout << a1 << '\n';          // 11

   a3 += a1;
   cout << a3 << '\n';          // 22

   return 0;
}
