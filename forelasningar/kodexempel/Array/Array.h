/*
 * Array.h    Container med fältliknande egenskaper, förenklad version.
 */
#ifndef ARRAY_H
#define ARRAY_H
#include <iosfwd>
#include <cstddef>

template<typename T, std::size_t N>
class Array 
{
public:
   // Kompilatorgenererad speciella medlemsfunktioner är bra.

   void fill(const T& value);

   // Storlek och kapacitet
   size_t size() const;
   size_t max_size() const;
   bool   empty() const;

   // Elementåtkomst
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

   // Byta innehåll med annan Array
   void swap(Array<T, N>& other);

private:
   T elems_[N ? N : 1];  // Storlek 0 är inte tillåtet, fält måste ha dimension > 0
};

// Byta innehåll med annan Array
template<typename T, std::size_t N>
void swap(Array<T, N>& x, Array<T, N>& y);

// Jämföra Array (==, !=, <, <=, > och >=)
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
