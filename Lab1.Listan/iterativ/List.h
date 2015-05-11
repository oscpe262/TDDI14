/*
 * List.h    Laboration Listan (iterativ)
 */
#ifndef LIST_H
#define LIST_H
#include <iosfwd>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iostream>
namespace linked_list {

  template <typename T>
  struct List_Node
  {
    T data_;
    List_Node<T>* next_;
    
    ~List_Node<T>() {delete next_ ;} // rekursiv destruktor, destruerar alla noder i listan
    
    explicit List_Node<T>(const T& value, List_Node<T>* lp = nullptr): data_(value), next_{lp} {} // konstruktor, minst ett värde in, nullptr om ett

    List_Node(const List_Node<T>&) = delete;
    List_Node& operator=(const List_Node<T>&) = delete;
  };

  /*===============================================*/
  template<typename T>
  struct List_iterator_
  {
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

    //defaultkonstruktor som sätter iteratorn till "förbi-sista"
    List_iterator_() : ln_p_ {nullptr} {}
    
    //konstruktor för att initiera med en pekare till en listnod
    explicit List_iterator_( List_Node<T>* other_p) : ln_p_ {other_p}{} 
    List_iterator_( const List_iterator_<T>& other) : ln_p_ {other.ln_p_}{} 

    List_iterator_<T>& operator=(const List_iterator_<T>& rhs) & {
      ln_p_ = rhs.ln_p_;
      return *this;
    }
		   
    //operator* ska returnera en referens till elementet i noden
    reference operator*() const {
      return ln_p_->data_;
    }
    
    //operator-> ska returnera en pekare till elementet i noden
    pointer operator->() const {
      return &(ln_p_->data_);
    }
    
    //operator++ i både prefix- och postfix-version för att stega iteratorn
    List_iterator_<T>& operator++() { //pre
      ln_p_ = ln_p_->next_;
      return *this;
    }
    
    List_iterator_<T> operator++(int) { //post - igenkänns genom dummy-int:en
      List_iterator_<T> tmp(*this);
      operator++();
      return tmp;
    }
      

    //operator== för att kontrollera om två iteratorer är lika, eller inte
    bool operator==(const List_iterator_<T>& rhs) const & {
      return (ln_p_ == rhs.ln_p_); 
    }

    //  operator!= för att kontrollera om två iteratorer är olika, eller inte
    bool operator!=(const List_iterator_<T>& rhs) const & {
      return !operator==(rhs);
    }

    //  pekare till listnod, representationen för iteratorn
    List_Node<T>* ln_p_ {nullptr};
  };

  template<typename T>
  struct List_const_iterator_
  {
    using value_type = T;
    using pointer = const T*;
    using reference = const T&;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

    //defaultkonstruktor som sätter iteratorn till "förbi-sista"
    List_const_iterator_() : ln_p_ {nullptr} {}
    //konstruktor för att initiera med en pekare till en listnod
    explicit List_const_iterator_( List_Node<T>* other_p) : ln_p_ {other_p}   {}
    List_const_iterator_( const List_iterator_<T>& l_i )  : ln_p_ {l_i.ln_p_} {}
    List_const_iterator_( const List_const_iterator_<T>& other) : ln_p_ {other.ln_p_} {}

    List_const_iterator_<T>& operator=(const List_const_iterator_<T>& rhs) & {
      ln_p_ = rhs.ln_p_;
      return *this;
    }
		   
    //operator* ska returnera en referens till const-elementet i noden
    const T& operator*() {
      return ln_p_->data_;
    }
    
    //operator-> ska returnera en pekare till const-elementet i noden
    const T* operator->() const {
     return &(ln_p_->data_);
    }
    
    //operator++ i både prefix- och postfix-version för att stega iteratorn
    List_const_iterator_<T>& operator++() { //pre
      ln_p_ = ln_p_->next_;
      return *this;
    }
    
    List_const_iterator_<T> operator++(int) { //post - igenkänns genom dummy-int:en
      List_const_iterator_<T> tmp(*this);
      operator++();
      return tmp;
    }
      

    //operator== för att kontrollera om två iteratorer är lika, eller inte
    bool operator==(const List_const_iterator_<T>& rhs) const & {
      return (ln_p_ == rhs.ln_p_); 
    }

    //  operator!= för att kontrollera om två iteratorer är olika, eller inte
    bool operator!=(const List_const_iterator_<T>& rhs) const & {
      return !operator==(rhs);
    }

    //  pekare till listnod, representationen för iteratorn
    List_Node<T> const * ln_p_ {nullptr};  // const List_Node<T>... == List_Node<T> const * ?
  };


  /*=========== ickemedlemsversioner för olika typer ============*/
  template<typename T>
  bool operator==(const List_iterator_<T>& lhs, const List_const_iterator_<T>& rhs) {
    return (lhs.ln_p_ == rhs.ln_p_);
  }

  template<typename T>
  bool operator!=(const List_iterator_<T>& lhs, const List_const_iterator_<T>& rhs) {
    return !operator==(lhs,rhs);
  }
  
  template<typename T>
  class List
  {
  public:
    using iterator = List_iterator_<T>;
    using const_iterator = List_const_iterator_<T>;
    
    
    /*======= Konstruktorer ==========*/
    List() = default; // defaultkonstruktor
    List(const List& other) { head_ = copy(other.head_) ; } // kopieringskonstruktor
    List(List&& other) { swap(other); }// movekonstruktor
    List(std::initializer_list<T> il) { // konstruktor via initierarlista
      try {
	for (auto it = il.begin() ; it != il.end() ;  ++it) {
	  append(*it); 
	}
      }
      catch(std::exception& e) {
	clear();
	std::cout << std::endl << e.what()
		  << std::endl << "Ett undantag inträffade under konstruktion: \n\t List(std::initializer_list<T> il)";
	     }
    }
  

    /*=========== Destruktor ==============*/
    ~List() { delete head_; }

    /*=========== Operatorer ==============*/
    
    List& operator= (const List& rhs) & { // kopieringstilldelningsoperator
      if (this != & rhs) {
	clear();
	List {rhs}.swap(*this);
      }
      return *this;
      
    }
    
    List& operator= (List&& rhs) & { // move-tilldelningsoperator
      delete head_;
      head_ = nullptr;
      swap(rhs);
      return *this;
    }


    /* ============= Medlemsfunktioner =============*/
    
    void insert(const T& value);
    void append(const T& value);
    void remove(const T& value);
    
    void swap(List<T>& rhs);
    
    void clear();
    
    bool empty() const;
    bool member(const T& value) const;
    
    iterator begin() {return iterator(head_) ;}
    const_iterator begin() const {return const_iterator(head_) ;}
    iterator end() {return iterator() ;}
    const_iterator end() const {return const_iterator() ;}
    const_iterator cbegin() const {return const_iterator(head_) ;}
    const_iterator cend() const {return const_iterator() ;}
    
    
  private:
    List_Node<T>* head_{ nullptr };
    static List_Node<T>* copy(List_Node<T>* other_p); // Privat kopieringsfunktion
  };

  template<typename T>
  void swap(List<T>& lhs, List<T>& rhs); // ickemedlemsswap


}


#include "List.tcc"
#endif
