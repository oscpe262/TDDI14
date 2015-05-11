/*
 * List.cc    Laboration Listan (rekursiv)
 */
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

// insert() sätter in ett värde först.
void List::insert(int value)
{
   head_ = new List_Node{ value, head_ };
}

// append() sätter in ett värde sist. 
void List::append(int value)
{
   append(value, head_);
}

void List::append(int value, List_Node*& list)
{
   if (list == nullptr) 
      list = new List_Node{ value, nullptr };
   else 
      append(value, list->next_);
}

// remove() tar bort den först hittade förekomsten av angivet värde, om det
// finns ett sådant värde.
void List::remove(int value)
{
   remove(value, head_);
}

void List::remove(int value, List_Node*& list)
{
   if (list == nullptr) 
   {
      return;
   }
   else if (list->data_ == value) 
   {
      List_Node*  garbage{ list };
      list = list->next_;
      garbage->next_ = nullptr;
      delete garbage;
   }
   else 
   {
      remove(value, list->next_);
   }
}

// clear() tömmer listan.
void List::clear()
{
   delete head_;
   head_ = nullptr;
}

// empty() returnerar sant om listan är tom, falskt annars.
bool List::empty() const
{
   return head_ == nullptr;
}

// member() returnerar sant om angivet värdet finns i listan, annars falskt.
bool List::member(int value) const
{
   return member(value, head_);
}

bool List::member(int value, const List_Node* list)
{
   if (list == nullptr) 
      return false;
   else if (list->data_ == value)
      return true;
   else
      return member(value, list->next_);
}

// print() skriver ut elementen i listan, med ett mellanrum mellan varje värde.
void List::print(ostream& os, const string& delimiter) const
{
   print(os, head_, delimiter);
}

void List::print(ostream& os, const List_Node* list, const string& delimiter)
{
   if (list != nullptr) 
   {
      os << list->data_ << (list->next_ ? delimiter : "");
      print(os, list->next_, delimiter);
   }
}
