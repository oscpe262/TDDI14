/*
 * CRN.cc
 */
#include "CRN.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace IDA_Person
{
   using namespace std;

   string CRN::str() const
   {
      ostringstream os;
      char filler = os.fill('0');
      os << year_ << setw(2) << month_ << setw(2) << day_ << '-' << birth_number_;
      os.fill(filler);
      return os.str();
   }

   ostream& operator<<(ostream& os, const CRN& crn)
   {
      return os << crn.str();
   }

} // namespace IDA_Person
