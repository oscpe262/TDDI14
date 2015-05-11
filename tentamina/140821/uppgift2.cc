/*
 * uppgift2.cc    TDDI14 2014-08-21
 */
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class round_robin_error : public std::length_error
{
public:
   round_robin_error(const std::string& what_arg) 
      : std::length_error(what_arg) {}
   round_robin_error(const char* what_arg) 
      : std::length_error(what_arg) {}
};

template<typename T, int Max_Size>
class Round_Robin
{
public:
   Round_Robin() = default;                                     // EJ KRAV
   Round_Robin(const Round_Robin&) = default;                   // EJ KRAV
   Round_Robin(Round_Robin&&) noexcept = default;               // EJ KRAV
   ~Round_Robin() = default;                                    // EJ KRAV
   Round_Robin& operator=(const Round_Robin&) & = default;      // EJ KRAV
   Round_Robin& operator=(Round_Robin&&) & noexcept = default;  // EJ KRAV

   bool empty() const { return elements_.empty(); }
   void add(const T& item);
   void reset() { iter_ = begin(elements_); }
   int  size() const { return elements_.size(); }
   int  max_size() const { return Max_Size; }

   T& operator*() { return *iter_; }  // om size() == 0, anropa inte!

   Round_Robin& operator++();
   Round_Robin  operator++(int);

private:
   using Container = std::vector<T>;
   Container elements_;
   typename Container::iterator iter_{ begin(elements_) };
};

template<typename T, int Max_Size>
void 
Round_Robin<T, Max_Size>::
add(const T& item)
{
   if (elements_.size() == Max_Size)
   {
      throw round_robin_error("Round_Robin: full");
   }
   elements_.push_back(item);
   reset();
}

template<typename T, int Max_Size>
Round_Robin<T, Max_Size>&
Round_Robin<T, Max_Size>::
operator++()
{
   if (!elements_.empty() && ++iter_ == end(elements_)) // check for wrap-around
   {
      iter_ = begin(elements_);
   }

   return *this;
}

template<typename T, int Max_Size>
Round_Robin<T, Max_Size>
Round_Robin<T, Max_Size>::
operator++(int)
{
   Round_Robin<T, Max_Size> tmp{*this};

   if (!elements_.empty() && ++iter_ == end(elements_)) // hantera cirkularitet
   {
      iter_ = begin(elements_);
   }

   return tmp;
}

int main()
{
   Round_Robin<int, 10>   rr1;
   Round_Robin<long, 100> rr2;

   for (int x : { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 })
   {
      try
      {
	 rr1.add(x);
	 
	 for (int i = 0; i < rr1.size(); ++i) 
	 {
	    cout << *rr1 << ' ';
	    ++rr1;
	 }
	 cout << '\n';
	 
	 rr2.add(x);
      }
      catch (const exception& e) 
      {
	 cout << e.what() << '\n';
	 break;
      }
   }
   
   for (int i = 0; i < rr2.size(); ++i) 
   {
      cout << *rr2++ << ' ';
      ++rr2;
   }
   cout << *rr2 << '\n';
  	   
   return 0;
}
