#include "Integer.h"

class copied_pointer {
public:
  //  copied_pointer(): p_{nullptr} {}; //default-konstruktor, redundant i.o.m. nästas default-värde
  copied_pointer( const Integer*& p = nullptr): p_{p} {}  //konstruktor (pekare till Integer, default till nullptr)
  copied_pointer( const copied_pointer& other) //konstruktor (kopiering)

  copied_pointer& operator=( const copied_pointer& rhs) /**/; //kopieringstilldelning möjlig
  ~copied_pointer()/**/; //destruktor, duh!

  copied_pointer( copied_pointer&& ){ //move-konstruktor
    copied_pointer{ rhs }.swap(*this);
  }
  copied_pointer& operator=( const copied_pointer&& rhs)/**/; // move-tilldelningsoperator 

  Integer operator*()/**/;
  Integer* operator->() /**/;

  bool operator!() {
    return p_ == nullptr;
  }

  void swap(copied_pointer& rhs){
    std::swap(p_, rhs.p_);
  }

 private:
  Integer* p_;
};
