/*
 * Array.h    Container med f�ltliknande egenskaper, f�renklad version.
 */
#ifndef ARRAY_H
#define ARRAY_H
#include <iosfwd>
#include <cstddef>

template<typename T, std::size_t N>
class Array 
{
public:
   // Kompilatorgenererad speciella medlemsfunktioner �r bra.

   void fill(const T& value);

   // Storlek och kapacitet
   size_t size() const;
   size_t max_size() const;
   bool   empty() const;

   // Element�tkomst
   T&       operator[](std::size_t n);
   const T& operator[](std::size_t n) const;

   T&       at(std::size_t n);
   const T& at(std::size_t n) const;

   T&       front();
   const T& front() const;
   T&       back();
   const T& back() const;

   T*       data();
   const T* data() const;

   // Byta inneh�ll med annan Array
   void swap(Array<T, N>& other);

private:
   T elems_[N ? N : 1];  // Storlek 0 �r inte till�tet, f�lt m�ste ha dimension > 0
};

// Byta inneh�ll med annan Array
template<typename T, std::size_t N>
void swap(Array<T, N>& x, Array<T, N>& y);

// J�mf�ra Array (==, !=, <, <=, > och >=)
template<typename T, std::size_t N>
bool operator==(const Array<T, N>& x, const Array<T, N>& y);

template<typename T, std::size_t N>
bool operator!=(const Array<T, N>& x, const Array<T, N>& y);

template<typename T, std::size_t N>
bool operator<(const Array<T, N>& x, const Array<T, N>& y);

template<typename T, std::size_t N>
bool operator>(const Array<T, N>& x, const Array<T, N>& y);

template<typename T, std::size_t N>
bool operator<=(const Array<T, N>& x, const Array<T, N>& y);

template<typename T, std::size_t N>
bool operator>=(const Array<T, N>& x, const Array<T, N>& y);

#include "Array.tcc"

#endif
