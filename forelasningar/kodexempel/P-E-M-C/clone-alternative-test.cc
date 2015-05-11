/*
 * clone-alternative-test.cc
 */
#include "CRN.h"
#include "Date.h"
#include "Person.h"
#include "Employee.h"
#include "Manager.h"
#include "Consultant.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
using namespace IDA_Person;
using namespace IDA_Date;

int main()
{
   Person* p{nullptr};

   Employee* pe{new Employee("Beth Saida",   CRN(1952,2,1,1021), Date(2007,1,2), 2, 12000.00)};

   p = new Employee(*pe);  // det går ju bra men då måste vi veta att det är en Employee, pe måste vara Employee*

   Person* pm{new Manager("Art Iculate",   CRN(1950,1,1,1011), Date(2007,1,1), 1, 41000.00, 2)};

   if (typeid(*pm) == typeid(Employee))  // måste använda typid här - exakt typ önskas!
   {
      p = new Employee(*dynamic_cast<Employee*>(pm));
   }
   else if (typeid(*pm) = typeid(Manager))
   {
      p = new Manager(*dynamic_cast<Manager*>(pm));
   }
   else if (typeid(*pm) = typeid(Consultant))
   {
      p = new Consultant(*dynamic_cast<Consultant*>(pm));
   }
   // Det var ju inte så kul...

   return 0;
}
