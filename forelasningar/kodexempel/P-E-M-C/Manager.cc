/*
 * Manager.cc
 */
#include "Manager.h"
#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

namespace IDA_Person
{
   using namespace std;

   string Manager::str() const
   {
      return Person::str() + " (Manager) " + get_employment_date().str() + ' ' 
	 + to_string(get_department());
   }

   void Manager::add_department_member(Employee* ep) const
   {
      // S�tt den anst�lldes avdelning till samma som Managerns
      ep->set_department(get_department());  // kr�ver v�nskap (friend)
      // L�gg till den anst�llde till avdelningens medlemmar 
      dept_members_.insert(make_pair(ep->get_employment_number(), ep));
   }

   void Manager::remove_department_member(int e_number) const
   {
      auto it = dept_members_.find(e_number);

      if (it != end(dept_members_))
      {
	 it->second->set_department(0);  // kr�ver v�nskap (friend)
	 dept_members_.erase(it);
      }
   }

   void Manager::print_department_list(ostream& os) const
   {
      cout << "Avdelning " << get_department() << "\n"
	   << setfill('-') << setw(60) << '-' << setfill(' ') << "\n";

      for (const auto& e : dept_members_)
      {
	 os << e.second->str() << " [" << e.second->get_salary() << "]\n";
      }
   }

   void Manager::raise_salary(double percent) const
   {
      for (const auto& e : dept_members_)
      {
	 double salary = e.second->get_salary();
	 salary += (percent * salary / 100.0);
	 e.second->set_salary(salary);  // kr�ver v�nskap (friend)
      }
   }

} // namespace IDA_Person
