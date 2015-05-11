/*
 * Person.cc
 */
#include "CRN.h"
#include "Person.h"
#include <string>

namespace IDA_Person
{
   using namespace std;

   ostream& operator<<(ostream& os, const Person& p)
   {
      return os << p.str();
   }

} // namespace IDA_Person
