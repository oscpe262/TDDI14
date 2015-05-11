/*
 * pemc-test.cc    Test program for Person-Employee-Manager-Consultant
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
   vector<Employee*> employees{
      new Manager{ "Art Iculate", CRN{ 1950,1,1,1011 }, Date{ 2007,1,1 }, 1, 41000.00, 2 },
      new Employee{ "Beth Saida", CRN{ 1952,2,1,1021 }, Date{ 2007,1,2 }, 2, 12000.00 },
      new Employee{ "Carl Ovignan", CRN{ 1953,3,1,1031 }, Date{ 2007,1,3 }, 3, 13000.00 },
      new Employee{ "Dan Druff", CRN{ 1954,4,1,1041 }, Date{ 2007,1,4 }, 4, 14000.00 },
      new Employee{ "Erica Ceous", CRN{ 1955,5,1,1051 }, Date{ 2007,1,5 }, 5, 15000.00 },
      new Manager{ "Frank Incence", CRN{ 1956,6,1,1061 }, Date{ 2007,1,6 }, 6, 52000.00, 1 },
      new Consultant{ "Ginger Snap", CRN{ 1957,7,1,1071 }, Date{ 2007,1,7 }, 6, 100000.00 },
      new Employee{ "Herb Acious", CRN{ 1955,5,1,1051 }, Date{ 2007,1,8 }, 5, 17000.00 },
      new Employee{ "Ivan Hoe",  CRN{ 1955,5,1,1051 }, Date{ 2007,1,9 }, 5, 12000.00 },
      new Employee{ "Jack Aroo", CRN{ 1955,5,1,1051 }, Date{ 2007,1,10 }, 5, 11000.00 },
      new Employee{ "Kale Yard", CRN{ 1955,5,1,1052 }, Date{ 2007,1,11 }, 5, 15000.00 },
   };

   cout << "Employee list\n" << setfill('-') << setw(52) << '-' << setfill(' ') << '\n';
   for (auto ep : employees)
   {
      cout << ep->str() << '\n';
   }
   cout << '\n';

   Manager* pm{ nullptr };

   for (auto ep : employees)
   {
      if (dynamic_cast<Manager*>(ep) != nullptr)
      {
         pm = dynamic_cast<Manager*>(ep);
      }
      else
      {
         pm->add_department_member(ep);
      }
   }

   for (auto ep : employees)
   {
      pm = dynamic_cast<Manager*>(ep);
      if (pm != nullptr)
      {
         pm->print_department_list(cout);
         cout << '\n';
      }
   }

   for (auto ep : employees)
   {
      pm = dynamic_cast<Manager*>(ep);
      if (pm != nullptr)
      {
         pm->raise_salary(10.0);
      }
   }

   for (auto ep : employees)
   {
      pm = dynamic_cast<Manager*>(ep);
      if (pm != nullptr)
      {
         pm->print_department_list(cout);
         cout << '\n';
      }
   }

   pm = dynamic_cast<Manager*>((*employees.begin()));

   pm->raise_salary(10.0);
   pm->print_department_list(cout);
   cout << '\n';

   pm->remove_department_member(2);
   pm->remove_department_member(4);  

   cout << "Employee list\n" << setfill('-') << setw(52) << '-' << setfill(' ') << '\n';
   for (auto ep : employees)
   {
      cout << ep->str() << '\n';
   }
   cout << '\n';

   Person* p = *begin(employees);  // råkar vara en Manager

   cout << "Using typeid (dynamic type is Manager):\n";
   if (typeid(*p) == typeid(Person))
      cout << "The first person in the employee list is a Person\n";
   else
      cout << "The first person in the employee list is NOT a Person (!)\n";

   if (typeid(*p) == typeid(Employee))
      cout << "The first person in the employee list is an Employee\n";
   else
      cout << "The first person in the employee list is NOT an Employee\n";

   if (typeid(*p) == typeid(Manager))
      cout << "The first person in the employee list is a Manager\n";
   else
      cout << "The first person in the employee list is NOT a Manager\n";

   if (typeid(*p) == typeid(Consultant))
      cout << "The first person in the employee list is a Consultant\n";
   else
      cout << "The first person in the employee list is NOT a Consultant\n";

   cout << "\nUsing dynamic_cast (dynamic type is Manager):\n";
   if (dynamic_cast<Person*>(p) != nullptr)
      cout << "The first person in the employee list is a Person\n";
   else
      cout << "The first person in the employee list is NOT a Person (!)\n";

   if (dynamic_cast<Employee*>(p) != nullptr)
      cout << "The first person in the employee list is an Employee\n";
   else
      cout << "The first person in the employee list is NOT an Employee\n";

   if (dynamic_cast<Manager*>(p) != nullptr)
      cout << "The first person in the employee list is a Manager\n";
   else
      cout << "The first person in the employee list is NOT a Manager\n";

   if (dynamic_cast<Consultant*>(p) != nullptr)
      cout << "The first person in the employee list is a Consultant\n";
   else
      cout << "The first person in the employee list is NOT a Consultant\n";
   
   p = *(++employees.begin());  // råkar vara en Employee

   cout << "\nUsing typeid (dynamic type is Employee):\n";
   if (typeid(*p) == typeid(Person))
      cout << "The first person in the employee list is a Person\n";
   else
      cout << "The first person in the employee list is NOT a Person (!)\n";

   if (typeid(*p) == typeid(Employee))
      cout << "The first person in the employee list is an Employee\n";
   else
      cout << "The first person in the employee list is NOT an Employee\n";

   if (typeid(*p) == typeid(Manager))
      cout << "The first person in the employee list is a Manager\n";
   else
      cout << "The first person in the employee list is NOT a Manager\n";

   if (typeid(*p) == typeid(Consultant))
      cout << "The first person in the employee list is a Consultant\n";
   else
      cout << "The first person in the employee list is NOT a Consultant\n";

   cout << "\nUsing dynamic_cast (dynamic type is Employee):\n";
   if (dynamic_cast<Person*>(p) != nullptr)
      cout << "The first person in the employee list is a Person\n";
   else
      cout << "The first person in the employee list is NOT a Person (!)\n";

   if (dynamic_cast<Employee*>(p) != nullptr)
      cout << "The first person in the employee list is an Employee\n";
   else
      cout << "The first person in the employee list is NOT an Employee\n";

   if (dynamic_cast<Manager*>(p) != nullptr)
      cout << "The first person in the employee list is a Manager\n";
   else
      cout << "The first person in the employee list is NOT a Manager\n";

   if (dynamic_cast<Consultant*>(p) != nullptr)
      cout << "The first person in the employee list is a Consultant\n";
   else
      cout << "The first person in the employee list is NOT a Consultant\n";

   // Test clone() 

   cout << "\nAn Employee is cloned:\n";
   Person* c{ p->clone() };
   cout << c->str() << '\n';
   delete c;
   c = nullptr;

   cout << "\nA Manager is cloned:\n";
   // This will make assertion fail, if Manager does not override do_clone().
   c = pm->clone();
   cout << c->str() << '\n';
   delete c;
   c = nullptr;

   // Deallocate employees in list and set pointers to null pointers (just for the exercise)
   for (auto& ep : employees)
   {
      delete ep;
      ep = nullptr;
   }

   return 0;
}
