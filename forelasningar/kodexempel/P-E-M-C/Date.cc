/*
 * Date.cc
 */
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

namespace IDA_Date
{
   using namespace std;

   string Date::str() const
   {
      ostringstream os;
      char filler = os.fill('0');
      os << year_ << '-' << setw(2) << month_ << '-' << setw(2) << day_;
      os.fill(filler);
      return os.str();
   }

   ostream& operator<<(ostream& os, const Date& d)
   {
      return os << d.str();
   }

} // namespace IDA_Date
