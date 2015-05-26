/*
 * variable_table.h
 */
#ifndef VARIABLETABLE_H
#define VARIABLETABLE_H
#include <iosfwd>
#include <stdexcept>
#include <string>
#include <map>

class Variable_Table
{
public:

  Variable_Table() = default;
  Variable_Table( const Variable_Table& ) = delete;
  Variable_Table& operator=( const Variable_Table&) = delete;
  
  
  void insert(const std::string&, double);
  void remove(const std::string&);
  bool find(const std::string&) const;
  void set_value(const std::string&, double);
  double get_value(const std::string&) const;
  void list( std::ostream& ) const;
  void clear();
  bool empty() const;

private:

  std::map<std::string, double> v_table_;
  
};

#endif
