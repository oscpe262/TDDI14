/*
 * CRN.h    Civic Registration Number
 */
#ifndef CRN_H
#define CRN_H
#include <iosfwd>
#include <string>

namespace IDA_Person
{
   class CRN
   {
   public:
      CRN(int year, int month, int day, int birth_number)
	 : year_{ year }, month_{ month }, day_{ day }, birth_number_{ birth_number }
      {}

      CRN(const CRN&) = default;
      CRN(CRN&&) = default;
      ~CRN() = default;

      CRN& operator=(const CRN&) = default;
      CRN& operator=(CRN&&) = default;

      int get_year() const { return year_; }
      int get_month() const { return month_; }
      int get_day() const { return day_; }
      int get_birth_number() const { return birth_number_; }

      std::string str() const;

   private:
      int year_;
      int month_;
      int day_;
      int birth_number_;
   };

   std::ostream& operator<<(std::ostream&, const CRN&);

} // namespace IDA_Person

#endif
