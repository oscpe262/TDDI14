/*
 * String.cc
 */
#include "String.h"
#include <algorithm>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

namespace IDA_String
{
   char String::empty_rep_[1];  // initieras till '\0' av kompilatorn

   String::String(const String& other) 
   {
      construct_(other.p_, other.size_);
   }

   String::String(String&& other) noexcept
   {
      swap(other);
   }

   String::String(const char* cstr)
   {
      construct_(cstr, strlen(cstr));
   }

   String::String(size_type n, char c) 
   {
      construct_(n, c);
   }

   String::String(initializer_list<char> il)
   {
      construct_(il);
   }

   String::~String()
   {
      if (!empty()) delete[] p_;
   }

   String& String::operator=(const String& rhs) &
   {
      String{rhs}.swap(*this);
      return *this;
   }

   String& String::operator=(String&& rhs) & noexcept
   {
      if (this != &rhs)
      {
	 clear();
	 swap(rhs);
      }
      return *this;
   }

   String& String::operator=(const char* rhs) &
   {
      String{rhs}.swap(*this);
      return *this;
   }

   String& String::operator=(char rhs) &
   {
      // Obs! String{1, rhs} skulle anropa String(initializer_list<char>)
      String(1, rhs).swap(*this);
      return *this;
   }

   String& String::operator=(initializer_list<char> rhs) &
   {
      String{rhs}.swap(*this);
      return *this;
   }

   String::size_type String::length() const
   {
      return size_;
   }

   bool String::empty() const
   {
      return size_ == 0;
   }

   void String::clear()
   {
      String{}.swap(*this);
   }

   char& String::operator[](size_type pos) 
   {
      return p_[pos];
   }

   char String::operator[](size_type pos) const
   {
      return p_[pos];
   }

   char& String::at(size_type pos)
   {
      if (size_ <= pos)  // size_type är unsigned
	 throw out_of_range{"String::at: index out of range"};
      return p_[pos];
   }

   char String::at(size_type pos) const
   {
      if (size_ <= pos)  // size_type är unsigned
	 throw out_of_range{"String::at: index out of range"};
      return p_[pos];
   }

   String& String::operator+=(const String& rhs)
   {
      if (!rhs.empty()) append_(rhs.p_);
      return *this;
   }

   String& String::operator+=(const char* rhs)
   {
      append_(rhs);
      return *this;
   }

   String& String::operator+=(char rhs)
   {
      append_(rhs);
      return *this;
   }

   String& String::operator+=(std::initializer_list<char> rhs)
   {
      return *this += String{rhs};
   }

   String operator+(const String& lhs, const String& rhs)
   {
      return String{lhs}.operator+=(rhs);
   }

   String operator+(const String& lhs, const char* rhs)
   {
      return String{lhs}.operator+=(rhs);
   }

   String operator+(const char* lhs, const String& rhs)
   {
      return String{lhs}.operator+=(rhs);
   }

   String operator+(const String& lhs, char rhs)
   {
      return String{lhs}.operator+=(rhs);
   }

   String operator+(char lhs, const String& rhs)
   {
      // Obs! String{1, lhs} skulle anropa String(initializer_list<char>)
      return String(1, lhs).operator+=(rhs);
   }

   const char* String::c_str() const
   {
      return p_;
   }

   String::operator const char*() const
   {
      return p_;
   }

   void String::swap(String& rhs) noexcept
   {
      std::swap(p_, rhs.p_);
      std::swap(size_, rhs.size_);
   }

   void swap(String& lhs, String& rhs) noexcept
   {
      lhs.swap(rhs);
   }

   bool operator==(const String& lhs, const String& rhs)
   {
      return strcmp(lhs.c_str(), rhs.c_str()) == 0;
   }

   bool operator==(const String& lhs, const char* rhs)
   {
      return strcmp(lhs.c_str(), rhs) == 0;
   }

   bool operator==(const char* lhs, const String& rhs)
   {
      return strcmp(lhs, rhs.c_str()) == 0;
   }

   bool operator!=(const String& lhs, const String& rhs)
   {
      return !(lhs == rhs);
   }

   bool operator!=(const String& lhs, const char* rhs)
   {
      return !(lhs == rhs);
   }

   bool operator!=(const char* lhs, const String& rhs)
   {
      return !(lhs == rhs);
   }

   bool operator<(const String& lhs, const String& rhs)
   {
      return strcmp(lhs.c_str(), rhs.c_str()) < 0;
   }

   bool operator<(const char* lhs, const String& rhs)
   {
      return strcmp(lhs, rhs.c_str()) < 0;
   }

   bool operator<(const String& lhs, const char* rhs)
   {
      return strcmp(lhs.c_str(), rhs) < 0;
   }

   bool operator<=(const String& lhs, const String& rhs)
   {
      return !(rhs < lhs);
   }

   bool operator<=(const char* lhs, const String& rhs)
   {
      return !(rhs < lhs);
   }

   bool operator<=(const String& lhs, const char* rhs)
   {
      return !(rhs < lhs);
   }

   bool operator>(const String& lhs, const String& rhs)
   {
      return rhs < lhs;
   }

   bool operator>(const char* lhs, const String& rhs)
   {
      return rhs < lhs;
   }

   bool operator>(const String& lhs, const char* rhs)
   {
      return rhs < lhs;
   }

   bool operator>=(const String& lhs, const String& rhs)
   {
      return !(lhs < rhs);
   }

   bool operator>=(const char* lhs, const String& rhs)
   {
      return !(lhs < rhs);
   }

   bool operator>=(const String& lhs, const char* rhs)
   {
      return !(lhs < rhs);
   }

   ostream& operator<<(ostream& os, const String& str)
   {
      return os << str.c_str();
   }

   istream& operator>>(istream& is, String& str)
   {
      static const int buf_size{ 1024 };
      char buf[buf_size];
      is >> setw(buf_size) >> buf;
      if (is) String{buf}.swap(str);
      return is;
   }

   istream& getline(istream& is, String& str, char delim)
   {
      static const int buf_size{ 1024 };
      char buf[buf_size];
      is.getline(buf, buf_size, delim);
      if (is) String{buf}.swap(str);
      return is;
   }

   void String::construct_(const char* cstr, size_type size)
   {
      if (cstr != nullptr && size > 0)  // nullptr-kontrollen är avsiktlig
      {
	 p_ = strcpy(new char[size + 1], cstr);
	 size_ = size;
      }
   }

   void String::construct_(size_type n, char c)
   {
      if (n > 0 && c != '\0')
      {
	 p_ = new char[n + 1];
	 memset(p_, c, n);
	 *(p_ + n)  = '\0';
	 size_ = n;
      }
   }

   void String::construct_(initializer_list<char> il)
   {
      if (il.size() > 0)
      {
	 size_ = il.size();
	 p_ = new char[size_ + 1];
	 std::copy(il.begin(), il.end(), p_);
	 p_[size_] = '\0';
      }
   }

   void String::append_(const char* cstr)
   {
      if (cstr != nullptr) {
	 size_type size{ size_ + strlen(cstr) };
	 char* p{ new char[size + 1] };
	 strcat(strcpy(p, p_), cstr);
	 if (!empty()) delete[] p_;
	 p_ = p;
	 size_ = size;
      }
   }

   void String::append_(char c)
   {
      if (c != '\0') {
	 char* p{ new char[size_ + 2] };
	 strcpy(p, p_);
	 p[size_] = c;
	 p[size_ + 1] = '\0';
	 if (!empty()) delete[] p_;
	 p_ = p;
	 size_ = size_ + 1;
      }
   }
} // namespace IDA_String
