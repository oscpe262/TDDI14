/*
 * Expression_Tree.cc
 */
#include "Expression_Tree.h"
#include "Expression.h"
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;

int const d_printlimit {4}; // Konstant för utskrift av doubles? 

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

double Assign::evaluate()
{
  double value { right_->evaluate() };
  dynamic_cast<Variable*>(left_)->set_value( value ); // Casta till Variable-pekare för att komma åt Variable's särskilda set_value
    return value;
}

double Divide::evaluate()
{
  return left_->evaluate() / right_->evaluate();
}

double Minus::evaluate()
{
  return left_->evaluate() - right_->evaluate();
}

double Plus::evaluate()
{
  return left_->evaluate() + right_->evaluate();
}

double Power::evaluate()
{
  return pow( left_->evaluate(), right_->evaluate() );
}

double Times::evaluate()
{
  return left_->evaluate() * right_->evaluate();
}

double Integer::evaluate()
{
  return static_cast<double>( value_ );
}

double Real::evaluate()
{
  return value_;
}

double Variable::evaluate()
{
  return value_;
}

/* ======== GET_POSTFIX ========== */

std::string Binary_Operator::get_postfix()
{
  return (left_->get_postfix() + ' ' +  right_->get_postfix() + ' ' + str() );
}

std::string Operand::get_postfix()
{
  return str();
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

