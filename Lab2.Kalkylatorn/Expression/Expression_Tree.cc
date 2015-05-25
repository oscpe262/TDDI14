/*
 * Expression_Tree.cc
 */
#include "Expression_Tree.h"
#include "Expression.h"
#include "variable_table.h"
#include <sstream>
#include <iomanip>
#include <math.h>
#include <typeinfo>
using namespace std;

/* ======== CLONE ========== */

Expression_Tree* Assign::clone()
{
  return new Assign{ *this };
}

Expression_Tree* Divide::clone()
{
  return new Divide{ *this };
}

Expression_Tree* Minus::clone()
{
  return new Minus{ *this };
}

Expression_Tree* Plus::clone()
{
  return new Plus{ *this };
}

Expression_Tree* Power::clone()
{
  return new Power{ *this };
}

Expression_Tree* Times::clone()
{
  return new Times{ *this };
}

Expression_Tree* Integer::clone()
{
  return new Integer{ *this };
}

Expression_Tree* Real::clone()
{
  return new Real{ *this };
}

Expression_Tree* Variable::clone()
{
  return new Variable{ *this };
}


/* ======== EVALUATE ========== */

double Assign::evaluate( Variable_Table& v_table )
{
  double value { right_->evaluate(v_table) };
  dynamic_cast<Variable*>(left_)->set_value( value ); // Casta till Variable-pekare för att komma åt Variable's särskilda set_value
  
  if ( v_table.find(left_->str()) ) {
    v_table.set_value(left_->str(), value);
  }
  else {
    v_table.insert(left_->str(), value);  
  }

  return value;
}

double Divide::evaluate( Variable_Table& v_table )
{
  return left_->evaluate(v_table) / right_->evaluate(v_table);
}

double Minus::evaluate( Variable_Table& v_table )
{
  return left_->evaluate(v_table) - right_->evaluate(v_table);
}

double Plus::evaluate( Variable_Table& v_table )
{
  return left_->evaluate(v_table) + right_->evaluate(v_table);
}

double Power::evaluate( Variable_Table& v_table )
{
  return pow( left_->evaluate(v_table), right_->evaluate(v_table) );
}

double Times::evaluate( Variable_Table& v_table )
{
  return left_->evaluate(v_table) * right_->evaluate(v_table);
}

double Integer::evaluate( Variable_Table& v_table )
{
  return static_cast<double>( value_ );
}

double Real::evaluate( Variable_Table& v_table )
{
  return value_;
}

double Variable::evaluate( Variable_Table& v_table )
{
  if ( v_table.find(str()) ){
    value_ = v_table.get_value(str());
    return value_;
  }
  // throw ...
}

/* ======== GET_POSTFIX ========== */

std::string Binary_Operator::get_postfix()
{
  return (left_->get_postfix()  + ' ' + str() + ' ' +  right_->get_postfix());
}

std::string Operand::get_postfix()
{
  return str();
}
/* ======== GET_INFIX ========== */

std::string Binary_Operator::get_infix()
{
  
  std::string left { left_->get_infix() };
  std::string right { right_->get_infix() };

  Binary_Operator* bopl { dynamic_cast<Binary_Operator*>(left_) };
  Binary_Operator* bopr { dynamic_cast<Binary_Operator*>(right_) };

  
  if ( bopl != nullptr )
    left = '(' + left + ')';
  if ( bopr != nullptr )
    right = '(' + right + ')';
  
  return ( left + ' ' + str() + ' ' + right);  
}

std::string Operand::get_infix()
{
  return str();
}

std::string Assign::get_infix()
{
  return ( left_->get_infix() + ' ' + str() + ' ' + right_->get_infix() );
  
}

/* ======== STR ========== */

string Assign::str()
{
  return "=";
}

string Divide::str()
{
  return "/";
}

string Minus::str()
{
  return "-";
}

string Plus::str()
{
  return "+";
}

string Power::str()
{
  return "^";
}

string Times::str()
{
  return "*";
}

string Integer::str()
{
  return to_string( value_ );
}

string Real::str()
{
  stringstream ss;
  ss << setprecision(15) << value_;
  return ss.str();
}

string Variable::str()
{
  return name_;
}


double Variable::get_value()
{
  return value_;
}

void Variable::set_value( double value )
{
  value_ = value;
}


/* ======== HELP FUNCS ========== */

void Binary_Operator::print(ostream& os, size_t depth = 1)
{
  right_->print( os, depth+1 );

  os << setw ( 2 * depth + 1 ) << ' '
     << '/' << endl
     << setw ( 2 * depth ) << ' '
     << str() << endl
     << setw ( 2 * depth + 1 ) << ' '
     << '\\' << endl;

  left_->print( os, depth+1 );
}

void Operand::print(ostream& os, size_t depth = 1)
{
  os << setw( 2 * depth ) << ' '
     << str() << endl;
}

