/*
 * Consultant.h
 */
#ifndef CONSULTANT_H
#define CONSULTANT_H
#include "Employee.h"
#include <string>

namespace IDA_Person
{
   class Consultant final : public Employee
   {
   public:
      using Employee::Employee;  // konstruktorer ärvs

      ~Consultant() = default;

      Consultant* clone() const override { return new Consultant{ *this }; }

      std::string str() const override;

   protected:
      Consultant(const Consultant&) = default;

   private:
      Consultant& operator=(const Consultant&) = delete;
   };

} // namespace IDA_Person

#endif
