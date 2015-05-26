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

class exptree_error : public std::logic_error
{
public:
  explicit exptree_error( const std::string& what_arg )
    : std::logic_error(what_arg) {}
  explicit exptree_error( const char* what_arg )
    : std::logic_error(what_arg) {}
};

/*
 * Expression_Tree är en abstrakt, polymorf basklass för alla trädnodklasser.
 */
class Expression_Tree
{
public:

  virtual ~Expression_Tree() = default;
  
  virtual double           evaluate( Variable_Table& v_table ) = 0;
  virtual std::string      get_infix() const = 0;
  virtual std::string      get_postfix() const = 0;
  virtual std::string      str() const = 0;

  virtual void             print(std::ostream&, size_t depth = 1) const = 0;
  virtual Expression_Tree* clone() = 0;
  
protected:
  Expression_Tree() = default;

};
/*
###################### B I N A R Y  O P E R A T O R #############################
 */
class Binary_Operator : public Expression_Tree
{
public:
  ~Binary_Operator() {delete left_ ; delete right_ ;}
  
  std::string get_infix() const override;
  std::string get_postfix() const override;
  void print(std::ostream&, size_t) const override;
  
protected:
  Binary_Operator(Expression_Tree* left, Expression_Tree* right)
    : Expression_Tree(), left_{ left }, right_{ right } {}
  Binary_Operator( const Binary_Operator& other )
    : Expression_Tree()
  {
    left_ = other.left_->clone();
    try
      {
	right_ = other.right_->clone();
      }
    catch(...)
      {
	delete left_;
	throw;
      }
  }
  Expression_Tree* left_;
  Expression_Tree* right_;

};

/*##################### O P E R A N D ##################################=*/

class Operand : public Expression_Tree
{
public:
  ~Operand() = default;

  std::string get_infix() const override;
  std::string get_postfix() const override;
  void print(std::ostream&, size_t) const override;
  
protected:
  Operand() : Expression_Tree() {}

};

//############################ A S S I G N ###############################

class Assign : public Binary_Operator
{ 
public:

  ~Assign() = default;

  Assign(Expression_Tree* left, Expression_Tree* right) : Binary_Operator{ left, right } {}

  std::string get_infix() const override;
  double evaluate( Variable_Table& v_table) override;
  std::string str() const override;
  Expression_Tree* clone() override;

protected:

  Assign( const Assign& other ) : Binary_Operator{ other.left_->clone(), other.right_->clone() } {}

};

//############################ P L U S ##################################

class Plus : public Binary_Operator
{ 
public:

  ~Plus() = default;
  
  Plus(Expression_Tree* left, Expression_Tree* right) : Binary_Operator{ left, right } {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() const override;
  Expression_Tree* clone() override;

protected:
  Plus( const Plus& other ): Binary_Operator{ other.left_->clone(),  other.right_->clone() } {}
  
};

// ############################# M I N U S ############################

class Minus : public Binary_Operator
{
public:

  ~Minus() = default;

  Minus(Expression_Tree* left, Expression_Tree* right) : Binary_Operator{ left, right } {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() const override;
  Expression_Tree* clone() override;

protected:

  Minus( const Minus& other ) : Binary_Operator{ other } {}

};

//############################# T I M E S ############################

class Times : public Binary_Operator
{
public:

  ~Times() = default;

  Times(Expression_Tree* left, Expression_Tree* right) : Binary_Operator{ left, right } {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() const override;
  Expression_Tree* clone() override;

protected:

  Times( const Times& other ) : Binary_Operator{ other } {}

};

//######################### D I V I D E ##############################

class Divide : public Binary_Operator
{

public:

  ~Divide() = default;

  Divide(Expression_Tree* left, Expression_Tree* right) : Binary_Operator{ left, right } {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() const override;
  Expression_Tree* clone() override;

protected:

  Divide( const Divide& other ) : Binary_Operator{ other } {}

};

//########################## P O W E R ##############################

class Power: public Binary_Operator
{

public:

  ~Power() = default;

  Power(Expression_Tree* left, Expression_Tree* right) : Binary_Operator{ left, right } {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() const override;
  Expression_Tree* clone() override;

protected:

  Power( const Power& other ) : Binary_Operator{ other } {}

};

//######################### I N T E G E R ###########################

class Integer : public Operand
{
public:

  ~Integer() = default;
  
  Integer( int value ) : Operand{}, value_{ value } {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() const override;
  Expression_Tree* clone() override;

protected:
  Integer( const Integer& ) = default;

  
private:
  int value_;
};

//########################  R E A L  ###############################

class Real : public Operand
{
public:

  ~Real() = default;
  
  Real( double value ) : Operand{}, value_{ value } {}

  double evaluate(  Variable_Table& v_table ) override;
  std::string str() const override;
  Expression_Tree* clone() override;

protected:
  Real( const Real& ) = default;
  
private:
  double value_;
  
};

//####################### V A R I A B L E ##########################

class Variable : public Operand
{

public:

  ~Variable() = default;

Variable( const std::string& name ) : Operand{}, name_{name}{}//, value_{ } {}

  double evaluate( Variable_Table& v_table ) override;
  std::string str() const override;
  Expression_Tree* clone() override;

protected:

  Variable( const Variable& ) = default;

private:
  std::string name_;

};

#endif
