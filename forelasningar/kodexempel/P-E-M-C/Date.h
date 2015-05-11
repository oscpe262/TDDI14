/*
 * Date.h
 */
#ifndef DATE_H
#define DATE_H
#include <iosfwd>
#include <string>

namespace IDA_Date
{
   class Date
   {
   public:
      Date(int year, int month, int day)
	 : year_{ year }, month_{ month }, day_{ day }
      {}

      Date(const Date&) = default;
      Date(Date&&) noexcept = default;
      ~Date() = default;

      Date& operator=(const Date&) & = default;
      Date& operator=(Date&&) & noexcept = default;

      int  get_year() const { return year_; }
      void set_year(int year) { year_ = year; }

      int  get_month() const { return month_; }
      void set_month(int month) { month_ = month; }

      int  get_day() const { return day_; }
      void set_day(int day) { day_ = day; }

      std::string str() const;

   private:
      int year_;
      int month_;
      int day_;
   };

   std::ostream& operator<<(std::ostream&, const Date&);

} // namespace IDA_Date

#endif
