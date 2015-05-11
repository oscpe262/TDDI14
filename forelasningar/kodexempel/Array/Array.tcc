/*
 * Array.tcc    Container med fältliknande egenskaper, förenklad version.
 */
#include <algorithm>
#include <iostream>
#include <cstddef>
#include <stdexcept>
using namespace std;

template<typename T, size_t N>
void 
Array<T, N>::
fill(const T& value)
{
   std::fill_n(elems_, elems_ + N, value);
}

// Storlek och kapacitet

template<typename T, size_t N>
size_t
Array<T, N>::
size() const
{
   return N;
}

template<typename T, size_t N>
size_t
Array<T, N>::
max_size() const
{
   return N;
}

template<typename T, size_t N>
bool
Array<T, N>::
empty() const
{
   return size() == 0;
}

// Elementåtkomst

template<typename T, size_t N>
T&
Array<T, N>::
operator[](std::size_t n)
{
   return elems_[n];
}

template<typename T, size_t N>
const T&
Array<T, N>::
operator[](std::size_t n) const
{
   return elems_[n];
}

template<typename T, size_t N>
T&
Array<T, N>::
at(std::size_t n)
{
   if (n >= N) throw out_of_range("Array::at"); 
   return elems_[n];
}

template<typename T, size_t N>
const T&
Array<T, N>::
at(std::size_t n) const 
{
   if (n >= N) throw out_of_range("Array::at");
   return elems_[n];
}

template<typename T, size_t N>
T&
Array<T, N>::
front()
{
   return elems_[0];
}

template<typename T, size_t N>
const T&
Array<T, N>::
front() const
{
   return elems_[0];
}

template<typename T, size_t N>
T&
Array<T, N>::
back()
{ 
   if (0 < N)
      return elems_[N - 1];
   else
      return elems_[N];
}

template<typename T, size_t N>
const T&
Array<T, N>::
back() const
{
   if (0 < N)
      return elems_[N - 1];
   else
      return elems_[N];
}

template<typename T, size_t N>
T*
Array<T, N>::
data()
{
   return &elems_[0];
}

template<typename T, size_t N>
const T*
Array<T, N>::
data() const
{
   return &elems_[0];
}

// Byta innehåll med annan container

template<typename T, size_t N>
void
Array<T, N>::
swap(Array<T, N>& other)
{
   std::swap_ranges(elems_, elems_ + N, other.elems_);
}

template<typename T, size_t N>
void
swap(Array<T, N>& x, Array<T, N>& y)
{
   x.swap(y);
}

// Jämförelser (==, !=, <, <=, > och >=)

template<typename T, size_t N>
bool 
operator==(const Array<T, N>& x, const Array<T, N>& y)
{
   return std::equal(x.data(), x.data() + x.size(), y.data());
}

template<typename T, size_t N>
bool
operator!=(const Array<T, N>& x, const Array<T, N>& y)
{
   return !(x == y);
}

template<typename T, size_t N>
bool
operator<(const Array<T, N>& x, const Array<T, N>& y)
{ 
   return std::lexicographical_compare(x.data(), x.data() + x.size(), 
				       y.data(), y.data() + y.size()); 
}

template<typename T, size_t N>
bool
operator>(const Array<T, N>& x, const Array<T, N>& y)
{
   return y < x;
}

template<typename T, size_t N>
bool
operator<=(const Array<T, N>& x, const Array<T, N>& y)
{
   return !(y < x);
}

template<typename T, size_t N>
bool
operator>=(const Array<T, N>& x, const Array<T, N>& y)
{
   return !(x < y);
}
