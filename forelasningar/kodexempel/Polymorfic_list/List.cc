/*
 * List.cc
 */
#include "List.h"
#include <iostream>
using namespace std;

/*
 * List
 */

List& List::operator=(const List& rhs) &
{
   List{ rhs }.swap(*this);
   return *this;
}

List& List::operator=(List&& rhs) & noexcept
{
   clear();
   swap(rhs);
   return *this;
}

void List::clear()
{
   if (!empty())
   {
      Data_Node* garbage = dynamic_cast<Data_Node*>(list_);
      Data_Node* p = garbage;

      while (!dynamic_cast<Null_Node*>(p->next_))
      {
	 p = dynamic_cast<Data_Node*>(p->next_);
      }

      // p pekar på datanoden direkt före nullnoden 

      list_ = p->next_;    // behåll nullnoden i listan
      p->next_ = nullptr;  // länka ur den
      delete garbage;      // radera datanodererna
   }
}

void swap(List& x, List& y) noexcept
{
   x.swap(y);
}

void List::print(ostream& os, const string& delimiter) const
{
   list_->print(os, delimiter);
}

/*
 * Data_Node
 */

Data_Node* Data_Node::insert(int value)
{
   if (value < data_)
   {
      return new Data_Node{ value, this };
   }
   else
   {
      next_ = next_->insert(value);
      return this;
   }
}

List_Node* Data_Node::remove(int value)
{
   if (value == data_)
   {
      List_Node* next = next_;
      next_ = nullptr;
      delete this;
      return next;
   }
   else
   {
      next_ = next_->remove(value);
      return this;
   }
}

const List_Node* Data_Node::find(int value) const
{
   if (data_ == value)
      return this;
   else
      return next_->find(value);
}

void Data_Node::print(ostream& os, const string& delimiter) const
{
   os << data_ << delimiter;
   next_->print(os, delimiter);
}

/*
 * Null_Node
 */

void Null_Node::print(ostream&, const string&) const
{
   return;
}
