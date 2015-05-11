/*
 * List.tcc    Laboration Listan (iterativ), template edition
 */
#include "List.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

namespace linked_list {
  // insert() s�tter in ett v�rde f�rst.
  template<typename T>
  void List<T>::insert(const T& value)
  {
    head_ = new List_Node<T>{ value, head_ };
  }

  // copy() �r en medlemsfunktion som anv�nds av klassen f�r att djupkopiera en List_Node-sekvens vars pekare vi returnerar
  template<typename T> // static i deklarationen
  List_Node<T>* List<T>::copy(List_Node<T>* other_p) //L�s p� om static members vs. non_static members
  {
    if (other_p == nullptr) {
      return other_p;
    }

    List copy_l;

    try {
      while( other_p != nullptr ) {
	copy_l.append(other_p->data_);
	other_p = other_p->next_;
      }
    }
    catch(std::exception& e) {
      delete copy_l.head
      std::cout << std::endl << e.what()
		<< std::endl << "Ett undantag intr�ffade: List<T>::copy(List_Node<T>* other_p" << std:: endl;
      return nullptr;
    }

    List_Node<T>* ret_p {copy_l.head_}; //copy_l �r en lokal variabel som destrueras n�r underprogrammet k�rts klart, vad h�nder med listan?
    copy_l.head_ = nullptr;

    return ret_p;
  }

  // append() s�tter in ett v�rde sist. 
  template<typename T>
  void List<T>::append(const T& value)
  {
    if (head_ == nullptr) 
      {
	head_ = new List_Node<T>{ value, nullptr };
      }
    else
      {
	List_Node<T>* last{ head_ };

	while (last->next_ != nullptr)
	  last = last->next_;

	last->next_ = new List_Node<T>{ value, nullptr };
      }
  }

  // remove() tar bort den f�rst hittade f�rekomsten av angivet v�rde, om det 
  // finns ett s�dant v�rde.
  template<typename T>
  void List<T>::remove(const T& value)
  {
    if (head_ == nullptr) 
      {
	return;
      }
    else if (head_->data_ == value) 
      {
	List_Node<T>* garbage{ head_ };
	head_ = head_->next_;
	garbage->next_ = nullptr;
	delete garbage;
      }
    else 
      {
	List_Node<T>* prev{ head_ };
	List_Node<T>* curr{ head_->next_ };

	while (curr != nullptr && curr->data_ != value)
	  {
	    prev = curr;
	    curr = curr->next_;
	  }

	if (curr != nullptr)
	  {
	    List_Node<T>* garbage{ curr };
	    prev->next_ = curr->next_;
	    garbage->next_ = nullptr;
	    delete garbage;
	  }
      }
  }

  // swap() byter "svansar" p� tv� listhuvuden
  template<typename T>
  void List<T>::swap(List<T>& rhs)
  {
    std::swap(head_, rhs.head_);
  }

  // clear() t�mmer listan.
  template<typename T>
  void List<T>::clear()
  {
    delete head_;
    head_ = nullptr;
  }

  // empty() returnerar sant om listan �r tom, falskt annars.
  template<typename T>
  bool List<T>::empty() const
  {
    return head_ == nullptr;
  }

  // member() returnerar sant om angivet v�rdet finns i listan, annars falskt.
  template<typename T>
  bool List<T>::member(const T& value) const
  {
    List_Node<T>* p{ head_ };

    while (p != nullptr && p->data_ != value)
      p = p->next_;

    return p != nullptr;
  }
}

template<typename T>
void linked_list::swap(List<T>& lhs, List<T>& rhs) { // ickemedlemsswap
  lhs.swap(rhs);
}


