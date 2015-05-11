/*
 * List.cc    Laboration Listan (iterativ)
 */
#include "List.h"
#include <iostream>
#include <string>
//#include <utility>
using namespace std;

namespace linked_list {
  // insert() s�tter in ett v�rde f�rst.
  void List::insert(int value)
  {
    head_ = new List_Node{ value, head_ };
  }

  // copy() �r en medlemsfunktion som anv�nds av klassen f�r att djupkopiera en List_Node-sekvens vars pekare vi returnerar
  List_Node* List::copy(List_Node* other_p) {
    if (other_p == nullptr) {
      return other_p;
    }

    /*  List_Node* copy_p {new List_Node {other_p->data_}};
	List_Node* ret_p {copy_p};

	other_p = other_p->next_;
  
	while (other_p != nullptr) {
	copy_p->next_ = {new List_Node {other_p->data_}};
	copy_p = copy_p->next_;
	other_p = other_p->next_;
	}

	return ret_p;
    */

    List copy_l;
    
    while( other_p != nullptr ) {
      copy_l.append(other_p->data_);
      other_p = other_p->next_;
    }

    List_Node* ret_p {copy_l.head_};
    copy_l.head_ = nullptr;

    return ret_p;
  }

  // append() s�tter in ett v�rde sist. 
  void List::append(int value)
  {
    if (head_ == nullptr) 
      {
	head_ = new List_Node{ value, nullptr };
      }
    else
      {
	List_Node* last{ head_ };

	while (last->next_ != nullptr)
	  last = last->next_;

	last->next_ = new List_Node{ value, nullptr };
      }
  }

  // remove() tar bort den f�rst hittade f�rekomsten av angivet v�rde, om det 
  // finns ett s�dant v�rde.
  void List::remove(int value)
  {
    if (head_ == nullptr) 
      {
	return;
      }
    else if (head_->data_ == value) 
      {
	List_Node* garbage{ head_ };
	head_ = head_->next_;
	garbage->next_ = nullptr;
	delete garbage;
      }
    else 
      {
	List_Node* prev{ head_ };
	List_Node* curr{ head_->next_ };

	while (curr != nullptr && curr->data_ != value)
	  {
	    prev = curr;
	    curr = curr->next_;
	  }

	if (curr != nullptr)
	  {
	    List_Node* garbage{ curr };
	    prev->next_ = curr->next_;
	    garbage->next_ = nullptr;
	    delete garbage;
	  }
      }
  }

  // swap() byter "svansar" p� tv� listhuvuden
  void List::swap(List& rhs)
  {
    std::swap(head_, rhs.head_);
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
    List_Node* p{ head_ };

    while (p != nullptr && p->data_ != value)
      p = p->next_;

    return p != nullptr;
  }

  // print() skriver ut elementen i listan, med 'delimiter' mellan varje v�rde.
  void List::print(ostream& os, const string& delimiter) const
  {
    for (List_Node* p = head_; p != nullptr; p = p->next_)
      os << p->data_ << (p->next_ ? delimiter : "");
  }


  void swap(List& lhs, List& rhs) { // ickemedlemsswap
    lhs.swap(rhs);
  }
}

