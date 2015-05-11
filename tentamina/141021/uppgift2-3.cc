/*
 * uppgift2-3.cc    TDDI14 2014-10-21
 */
#include <iostream>
using namespace std;

template<typename T>
class Adder
{
public:
   explicit Adder(const T& init = T{}) : value_{ init } {}

   Adder(const Adder&) = default;
   Adder(Adder&&) = default;
   ~Adder() = default;
   Adder& operator=(const Adder&) = default;
   Adder& operator=(Adder&&) = default;

   Adder& operator=(const T& rhs)
   {
      value_ = rhs; 
      return *this;
   }

   Adder& operator+=(const Adder& rhs) 
   { 
      value_ += rhs.value_; 
      return *this;
   }

   Adder& operator+=(const T& rhs) 
   { 
      value_ += rhs; 
      return *this;
   }

   template<typename U>
   friend ostream& operator<<(ostream&, const Adder<U>&);

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
ostream& operator<<(ostream& os, const Adder<T>& as)
{
   return os << as.value_;
}

int main()
{
   Adder<int> as1;
   cout << as1 << '\n';          // 0

   as1 += 5;
   cout << as1 << '\n';          // 5

   as1 = 11;
   cout << as1 << '\n';          // 11

   Adder<int> as2{ 10 };
   cout << as2 << '\n';          // 10

   cout << (as1 + as2) << '\n';  // 21

   Adder<int> as3{ as2 };
   cout << as3 << '\n';          // 10

   as3 = as1;
   cout << as1 << '\n';          // 11

   as3 += as1;
   cout << as3 << '\n';          // 22

   return 0;
}
