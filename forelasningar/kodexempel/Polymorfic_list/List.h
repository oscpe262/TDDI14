/*
 * List.h
 */
#ifndef POLYLIST_H
#define POLYLIST_H
#include <iosfwd>
#include <string>
#include <iterator>

struct List_Node
{
   List_Node() = default;
   List_Node(const List_Node&) = delete;

   virtual ~List_Node() = default;

   List_Node& operator=(const List_Node&) = delete;

   virtual List_Node* insert(int value) = 0;
   virtual List_Node* remove(int value) = 0;
   virtual const List_Node* find(int value) const = 0;

   virtual int  length() const = 0;
   virtual bool empty() const = 0;

   virtual List_Node* clone() const = 0;

   virtual void print(std::ostream& os, const std::string& delimiter) const = 0;
};

struct Data_Node : public List_Node
{
   Data_Node(int value, List_Node* next) : data_{ value }, next_{ next } {}
   Data_Node(const Data_Node&) = delete;

   ~Data_Node() { delete next_; }

   Data_Node& operator=(const Data_Node&) = delete;

   Data_Node* insert(int value) override;
   List_Node* remove(int value) override;
   const List_Node* find(int value) const override;

   int  length() const override { return 1 + next_->length(); }
   bool empty() const override { return false; }

   Data_Node* clone() const override { return new Data_Node{ data_, next_->clone() }; }

   void print(std::ostream& os, const std::string& delimiter) const override;

   int        data_;
   List_Node* next_;
};

struct Null_Node final : public List_Node
{
   Null_Node() = default;
   Null_Node(const Null_Node&) = delete;

   ~Null_Node() = default;

   Null_Node& operator=(const Null_Node&) = delete;

   Data_Node* insert(int value) override { return new Data_Node{ value, this }; }
   Null_Node* remove(int) override { return this; }
   const List_Node* find(int) const override { return nullptr; }

   int  length() const override { return 0; }
   bool empty() const override { return true; }

   Null_Node* clone() const override { return new Null_Node; }

   void print(std::ostream& os, const std::string& delimiter) const override;
};

class List 
{
public:
   List() : list_{ new Null_Node } {}
   List(const List& other) : list_{ copy(other.list_) } {}
   List(List&& other) : List() { swap(other); }

   ~List() { delete list_; }

   List& operator=(const List& rhs) &;
   List& operator=(List&& rhs) & noexcept;

   void insert(int value) { list_ = list_->insert(value); }
   void remove(int value) { list_ = list_->remove(value); }
   bool member(int value) const { return list_->find(value) != nullptr; }
 
   int  length() const { return list_->length(); }
   bool empty() const { return list_->empty(); }
   void clear();
   
   void swap(List& other) noexcept { std::swap(list_, other.list_); }
   
   void print(std::ostream& os, const std::string& delimiter = " ") const;

private:
   List_Node* list_;

   static List_Node* copy(const List_Node* list) { return list->clone(); }
};

void swap(List&, List&) noexcept;

#endif
