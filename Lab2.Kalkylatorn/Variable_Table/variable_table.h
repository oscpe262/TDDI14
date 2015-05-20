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
  void insert(std::string, double);
  void remove(std::string);
  bool find(std::string) const;
  void set_value(std::string, double);
  std::string get_value(std::string) const;
  void list( std::ostream& ) const;
  void clear();
  bool empty() const;

private:

  map<std::string, double> v_table_;
  
}

#endif
