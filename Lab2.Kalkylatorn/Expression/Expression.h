/*
 * Expression.h
 */
#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iosfwd>
#include <stdexcept>
#include <string>

class Expression
{
public:

  ~Expression() { delete trunk_;}
  
  explicit Expression( Expression_Tree* trunk = nullptr)
    : trunk_{trunk} {}
  
  Expression(const Expression& other)
    : trunk_{nullptr}
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
  
  std::string get_postfix() const;
  
  bool empty() const;
  void print_tree(std::ostream&) const;
  
  void swap(Expression&);

private:
  Expression_Tree* trunk_;
};

void swap(Expression&, Expression&);

Expression make_expression(const std::string& infix);

#endif
