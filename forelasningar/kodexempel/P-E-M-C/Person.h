/*
 * Person.h
 */
#ifndef PERSON_H
#define PERSON_H
#include "CRN.h"
#include <iosfwd>
#include <string>

namespace IDA_Person
{
   class Person
   {
   public:
      virtual ~Person() = default;

      virtual Person* clone() const = 0;

      virtual std::string str() const { return name_ + ' ' + crn_.str(); }

      std::string get_name() const { return name_; }
      void        set_name(const std::string& name) { name_ = name; }

      CRN         get_crn() const { return crn_; }
      void        set_crn(const CRN& crn) { crn_ = crn; }

   protected:
      Person(const std::string& name, const CRN& crn)
         : name_{ name }, crn_{ crn }
      {}

      Person(const Person&) = default;
 
   private:
      Person& operator=(const Person&) = delete;

      std::string name_;
      CRN         crn_;
   };

   std::ostream& operator<<(std::ostream&, const Person&);

} // namespace IDA_Person

#endif
