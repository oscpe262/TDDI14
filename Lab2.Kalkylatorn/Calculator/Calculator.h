/*
 * Calculator.h
 */
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Expression.h"
#include <iosfwd>
#include <deque>

/**
 * Calculator är en klass för hantering av enkla aritmetiska uttryck.
 */
class Calculator
{
public:
   Calculator()
     : c_arg_{0} {};

   Calculator(const Calculator&) = delete;
   Calculator& operator=(const Calculator&) = delete;

   void run();

private:
  static const std::string valid_command_;

  Expression current_expression_;

  char command_;
  size_t c_arg_;
  std::deque<Expression> exp_history_ ;
  
  void print_help() const;
  void get_command();
  bool valid_command() const;
  void execute_command();
  
  void read_expression(std::istream&);
};

#endif
