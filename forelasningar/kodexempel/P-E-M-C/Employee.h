/*
 * Employee.h
 */
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "CRN.h"
#include "Date.h"
#include "Person.h"
#include <string>

namespace IDA_Person
{
   using IDA_Date::Date;

   class Employee : public Person
   {
   public:
      Employee(const std::string& name,
               const CRN&         crn,
               const Date&        e_date,
               int                e_nbr,
               double             salary,
               int                dept = 0)
         : Person{name, crn},
         e_date_{ e_date }, e_number_{ e_nbr }, salary_{ salary }, dept_{ dept }
      {}

      ~Employee() = default;

      Employee* clone() const override { return new Employee{ *this }; }

      std::string str() const override;

      int    get_department() const { return dept_; }
      Date   get_employment_date() const { return e_date_; }
      int    get_employment_number() const { return e_number_; }
      double get_salary() const { return salary_; }

   protected:
      Employee(const Employee&) = default;

   private:
      Employee& operator=(const Employee&) = delete;

      friend class Manager;
      void set_department(int dept) { dept_ = dept; }
      void set_salary(double salary) { salary_ = salary; }

      Date      e_date_;
      const int e_number_;
      double    salary_;
      int       dept_;
   };

} // namespace IDA_Person

#endif
