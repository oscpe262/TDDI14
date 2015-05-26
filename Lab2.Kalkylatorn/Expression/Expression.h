/*
 * Expression.h
 */
#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iosfwd>
#include <stdexcept>
#include <string>

class expression_error : public std::logic_error
{
public:
  explicit expression_error( const std::string& what_arg )
    : std::logic_error(what_arg) {}
  explicit expression_error( const char* what_arg )
    : std::logic_error(what_arg) {}
};

class Expression
{
public:

  ~Expression() { delete trunk_;}
  
  
  explicit Expression( Variable_Table* v_tablep, Expression_Tree* trunk = nullptr)
    : trunk_{trunk}, ref_tablep_{v_tablep} {}
  
  Expression(const Expression& other)
    : trunk_{nullptr}, ref_tablep_{other.ref_tablep_}
  {
	if (other.trunk_!=nullptr)
	  trunk_ = other.trunk_->clone();
  }
  
  Expression(Expression&& other){swap(other);}
  
  /*tilldelning*/
  
  // kopiering
  Expression& operator=(const Expression& rhs) & 
  {
    if (this != &rhs)
      {
	delete trunk_;
	trunk_=nullptr;
	Expression{rhs}.swap(*this);
      }
    return *this;
  }

  // flytt
  Expression& operator =( Expression&& rhs) &
  {
    delete trunk_;
    trunk_ = nullptr;
    swap(rhs);
    return *this;
  }

  long double evaluate() const;
  
  std::string get_infix() const;
  std::string get_postfix() const;
  
  bool empty() const;
  void print_tree(std::ostream&) const;
  
  void swap(Expression&);

private:
  Expression_Tree* trunk_;
  Variable_Table* ref_tablep_;
};

void swap(Expression&, Expression&);

Expression make_expression(Variable_Table*, const std::string& infix);

#endif
