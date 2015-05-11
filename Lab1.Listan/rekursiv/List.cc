/*
 * List.cc    Laboration Listan (rekursiv)
 */
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

// insert() s�tter in ett v�rde f�rst.
void List::insert(int value)
{
   head_ = new List_Node{ value, head_ };
}

// append() s�tter in ett v�rde sist. 
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

// remove() tar bort den f�rst hittade f�rekomsten av angivet v�rde, om det
// finns ett s�dant v�rde.
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

// clear() t�mmer listan.
void List::clear()
{
   delete head_;
   head_ = nullptr;
}

// empty() returnerar sant om listan �r tom, falskt annars.
bool List::empty() const
{
   return head_ == nullptr;
}

// member() returnerar sant om angivet v�rdet finns i listan, annars falskt.
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

// print() skriver ut elementen i listan, med ett mellanrum mellan varje v�rde.
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
