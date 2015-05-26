/*
 * Calculator.h
 */
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Expression.h"
#include "variable_table.h"
#include <iosfwd>
#include <deque>

/*
 * Calculator är en klass för hantering av enkla aritmetiska uttryck.
 */
class Calculator
{
public:
   Calculator()
     : c_arg_{0}, current_expression_{Expression(&v_table_)} {}

   Calculator(const Calculator&) = delete;
   Calculator& operator=(const Calculator&) = delete;

   void run();

private:
  size_t c_arg_;

  static const std::string valid_command_;

  char command_;
  Variable_Table v_table_;
  Expression current_expression_;
  std::deque<Expression> exp_history_ ;
  
  void print_help() const;
  void get_command();
  bool valid_command() const;
  void execute_command();
  
  void read_expression(std::istream&);
};

#endif
