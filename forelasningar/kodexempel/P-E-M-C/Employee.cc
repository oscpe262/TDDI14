/*
 * Employee.cc
 */
#include "CRN.h"
#include "Date.h"
#include "Employee.h"
#include <string>

namespace IDA_Person
{
   using namespace std;

   string Employee::str() const
   {
      return Person::str() + " (Employee) " + e_date_.str() + ' '
	 + to_string(dept_);
   }

} // namespace IDA_Person
