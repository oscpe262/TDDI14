/*
 * Expression.h
 */
#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iosfwd>
#include <stdexcept>
#include <string>

/**
 * expression_error kastas om fel intr�ffar i en Expression-operation.
 * Ett diagnostiskt meddelande ska skickas med.
 */
// ATT G�RA!

/**
 * Expression �r en klass f�r att representera ett enkelt aritmetiskt uttryck.
 */
class Expression
{
public:
   // VIKTIGA SAKER �TERST�R ATT FIXA OCH �VEN ATT MODIFIERA!

   Expression() = default;

   Expression(class Expression_Tree*) {}

   long double evaluate() const;

   std::string get_postfix() const;

   bool empty() const;
   void print_tree(std::ostream&) const;

   void swap(Expression&);
};

void swap(Expression&, Expression&);

Expression make_expression(const std::string& infix);

#endif
