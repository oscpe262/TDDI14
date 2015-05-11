/*
 * Consultant.cc
 */
#include "Consultant.h"
#include "CRN.h"
#include "Date.h"
#include <string>

namespace IDA_Person
{
   using namespace std;

   string Consultant::str() const
   {
      return Person::str() + " (Consultant) " + get_employment_date().str() + ' ' 
	 + to_string(get_department());
   }

} // namespace IDA_Person
