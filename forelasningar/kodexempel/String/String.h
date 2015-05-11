/*
 * String.h
 */
#ifndef STRING_H
#define STRING_H
#include <cstddef>
#include <initializer_list>
#include <iosfwd>
#include <iterator>

namespace IDA_String
{
   class String
   {
   public:
      using size_type              = std::size_t;
      using iterator               = char*;
      using const_iterator         = const char*;
      using reverse_iterator       = std::reverse_iterator<iterator>;
      using const_reverse_iterator = std::reverse_iterator<const_iterator>;

      // Konstruktorer och destruktor
      String() = default;
      String(const String&);
      String(String&&) noexcept;
      String(const char*);
      String(size_type, char);
      String(std::initializer_list<char>);
      ~String(); 

      // Tilldelning
      String& operator=(const String&) &;
      String& operator=(String&&) & noexcept;
      String& operator=(const char*) &;
      String& operator=(char) &;
      String& operator=(std::initializer_list<char>) &;

      // Iteratorer
      iterator       begin() { return iterator(p_); }
      const_iterator begin() const { return const_iterator(p_); }
      iterator       end() { return iterator(p_ + size_); }
      const_iterator end() const { return const_iterator(p_ + size_); }
      
      reverse_iterator       rbegin() { return reverse_iterator(end()); }
      const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
      reverse_iterator       rend() { return reverse_iterator(begin()); }
      const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
      
      const_iterator         cbegin() const { return const_iterator(p_); }
      const_iterator         cend() const { return const_iterator(p_ + size_); }
      const_reverse_iterator crbegin() const { return const_reverse_iterator(end()); }
      const_reverse_iterator crend() const { return const_reverse_iterator(begin()); }

      // Elementåtkomst
      char& operator[](size_type);
      char  operator[](size_type) const;
      char& at(size_type);
      char  at(size_type) const;

      // Storlek
      size_type length() const;
      bool      empty() const;
      void      clear();

      // Strängsammansättning (en tänkbar flyttversion utelämnad)
      String& operator+=(const String&);
      String& operator+=(const char*);
      String& operator+=(char);
      String& operator+=(std::initializer_list<char>);

      // Konvertering till C-sträng
      const char* c_str() const;
      explicit operator const char*() const;

      // Byta innehåll med annan String
      void swap(String&) noexcept;

   private:
      static char empty_rep_[1];  // tom, null-avslutad C-sträng

      size_type size_{ 0 };
      char* p_{ empty_rep_ };

      // Interna hjälpfunktioner
      void construct_(const char*, size_type);
      void construct_(size_type, char);
      void construct_(std::initializer_list<char>);
      void append_(const char*);
      void append_(char);
   };

   // Strängsammansättning (sju möjliga flyttversioner utelämnade)
   String operator+(const String&, const String&);
   String operator+(const char*, const String&);
   String operator+(const String&, const char*);
   String operator+(const String&, char);
   String operator+(char, const String&);

   // Test av likhet och olikhet
   bool operator==(const String&, const String&);
   bool operator==(const char*, const String&);
   bool operator==(const String&, const char*);
   bool operator!=(const String&, const String&);
   bool operator!=(const char*, const String&);
   bool operator!=(const String&, const char*);

   // Jämförelser
   bool operator<(const String&, const String&);
   bool operator<(const char*, const String&);
   bool operator<(const String&, const char*);
   bool operator<=(const String&, const String&);
   bool operator<=(const char*, const String&);
   bool operator<=(const String&, const char*);
   bool operator>(const String&, const String&);
   bool operator>(const char*, const String&);
   bool operator>(const String&, const char*);
   bool operator>=(const String&, const String&);
   bool operator>=(const char*, const String&);
   bool operator>=(const String&, const char*);

   // In- och utmatning
   std::ostream& operator<<(std::ostream&, const String&);
   std::istream& operator>>(std::istream&, String&);
   std::istream& getline(std::istream&, String&, char = '\n');

   // Byta innehåll på två String-objekt
   void swap(String&, String&) noexcept;

} // namespace IDA_String

#endif
