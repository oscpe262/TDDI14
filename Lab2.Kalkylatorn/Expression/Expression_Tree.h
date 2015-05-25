/*
 * Expression_Tree.h
 */
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include "variable_table.h"
#include <iosfwd>
#include <string>
#include <stdexcept>
#include <iostream>
#include <typeinfo>
/*
 * expression_tree_error kastas om fel uppst�r i en Expression_Tree-operation.
 * Ett diagnostiskt meddelande ska kunna skickas med.
 */
// ATT G�RA!

/*
 * Expression_Tree �r en abstrakt, polymorf basklass f�r alla tr�dnodklasser.
 */
class Expression_Tree
{
public:
   // VIKTIGA SAKER KVAR ATT T�NKA P�! TILL EXEMPEL INITIERING, KOPIERING
   // OCH DESTRUERING! DET KAN �VEN T�NKAS ATT VIKTIGA MODIFIERINGAR BEH�VS.

  virtual ~Expression_Tree() = default;

  // Expression_Tree ( const Expression_Tree &) = delete;
  // Expression_Tree ( const Expression_Tree &) = delete;
  
  virtual double           evaluate( Variable_Table& v_table ) = 0;
  virtual std::string      get_infix() = 0;
  virtual std::string      get_postfix() = 0;
  virtual std::string      str() = 0;

  virtual void             print(std::ostream&, size_t depth = 1) = 0;
  virtual Expression_Tree* clone() = 0;
  
protected:
  Expression_Tree() = default;

};

class Binary_Operator : public Expression_Tree
{
public:
  ~Binary_Operator() {delete left_ ; delete right_ ;}

  // kop kon/till = del?
  
  std::string get_infix() override;
  std::string get_postfix() override;
  void print(std::ostream&, size_t) override;
  
protected:
  Binary_Operator(Expression_Tree* left, Expression_Tree* right)
    : Expression_Tree(), left_{ left }, right_{ right } {}

  Expression_Tree* left_;
  Expression_Tree* right_;

private:	
};

/*========*/

class Operand : public Expression_Tree
{
public:
  ~Operand() = default;

  std::string get_infix() override;
  std::string get_postfix() override;
  void print(std::ostream&, size_t) override;
  
protected:
  Operand() : Expression_Tree() {}

private:
};


class Assign : public Binary_Operator
{ 
public:

  ~Assign() = default;

  Assign(Expression_Tree* left, Expression_Tree* right)
    : Binary_Operator{ left, right } {}

  std::string get_infix() override;
  double evaluate( Variable_Table& v_table) override;
  std::string str() override;
  Expression_Tree* clone() override;

protected:

  Assign( const Assign& other )
    : Binary_Operator{ other.left_->clone(), other.right_->clone() } {}

private:
  
};

class Plus : public Binary_Operator
{ 
public:

  ~Plus() = default;
  
  Plus(Expression_Tree* left, Expression_Tree* right)
    : Binary_Operator{ left, right } {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() override;
  Expression_Tree* clone() override;

protected:
  Plus( const Plus& other )
    : Binary_Operator{ other.left_->clone(),  other.right_->clone() } {}
  
};

class Minus : public Binary_Operator
{
public:

  ~Minus() = default;

  Minus(Expression_Tree* left,
	Expression_Tree* right)
    : Binary_Operator{ left, right }
  {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() override;
  Expression_Tree* clone() override;

protected:

  Minus( const Minus& other )
    : Binary_Operator{ other.left_->clone(), other.right_->clone() }
  {}

private:

};


class Times : public Binary_Operator
{
public:

  ~Times() = default;

  Times(Expression_Tree* left,
	Expression_Tree* right)
    : Binary_Operator{ left, right }
  {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() override;
  Expression_Tree* clone() override;

protected:

  Times( const Times& other )
    : Binary_Operator{ other.left_->clone(), other.right_->clone() }
  {}

private:

};

class Divide : public Binary_Operator
{

public:

  ~Divide() = default;

  Divide(Expression_Tree* left,
	 Expression_Tree* right)
    : Binary_Operator{ left, right }
  {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() override;
  Expression_Tree* clone() override;

protected:

  Divide( const Divide& other )
    : Binary_Operator{ other.left_->clone(), other.right_->clone() }
  {}

private:

};

class Power: public Binary_Operator
{

public:

  ~Power() = default;

  Power(Expression_Tree* left,
	Expression_Tree* right)
    : Binary_Operator{ left, right }
  {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() override;
  Expression_Tree* clone() override;

protected:

  Power( const Power& other )
    : Binary_Operator{ other.left_->clone(), other.right_->clone() }
  {}

private:
};


class Integer : public Operand
{
public:

  ~Integer() = default;
  
  Integer( int value )
    : Operand{}, value_{ value } {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() override;
  Expression_Tree* clone() override;

protected:
  Integer( const Integer& ) = default;

  
private:
  int value_;
};

class Real : public Operand
{
public:

  ~Real() = default;
  
  Real( double value )
    : Operand{}, value_{ value } {}

  double evaluate(  Variable_Table& v_table ) override;
  std::string str() override;
  Expression_Tree* clone() override;

protected:
  Real( const Real& ) = default;
  
private:
  double value_;
  
};

class Variable : public Operand
{

public:

  ~Variable() = default;

  Variable( const std::string& name )
    : Operand{}, name_{name}, value_{ }
  {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() override;
  Expression_Tree* clone() override;
  double get_value();
  void set_value( double );

protected:

  Variable( const Variable& ) = default;

private:
  std::string name_;
  double value_;

};

#endif
