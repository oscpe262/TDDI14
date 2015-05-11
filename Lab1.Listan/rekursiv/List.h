/*
 * List.h    Laboration Listan (rekursiv)
 */
#ifndef LIST_H
#define LIST_H
#include <iosfwd>
#include <string>

struct List_Node
{
   int        data_;
   List_Node* next_;
};

class List
{
public:
   List() = default;

   ~List() { delete head_; }
      
   void insert(int value);
   void append(int value);
   void remove(int value);

   void clear();

   bool empty() const;
   bool member(int value) const;

   void print(std::ostream&, const std::string& delimiter = " ") const;

private:
   struct List_Node* head_{ nullptr };

   static void append(int value, List_Node*& list);
   static void remove(int value, List_Node*& list);
   static bool member(int value, const List_Node* list);

   static void print(std::ostream& os, 
		     const List_Node* list, 
		     const std::string& delimiter);
};

#endif
