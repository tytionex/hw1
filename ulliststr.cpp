#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// How to return const reference?

std::string const & ULListStr::back() const {
  
  if(head_ == nullptr){
    throw std::invalid_argument("Bad location");
  }
  return tail_ -> val[tail_ -> last-1];
}
std::string const & ULListStr::front() const{
  
  if(tail_ == nullptr){
    throw std::invalid_argument("Bad location");
  }
  // elegant solution from Denis
  return head_ -> val[head_ -> first];
}
void ULListStr::pop_front()
{
  head_ -> val[head_ -> first] = " ";
  head_ -> first++;
  size_--; 

  if(head_ -> first == head_ -> last)
  {
    
    Item *nextNode = head_ -> next; 
    Item *temp = head_;
    if(nextNode != nullptr){
      temp -> next -> prev = nullptr; 
      temp -> next = nullptr; 
      temp = head_ -> next; 
      delete head_;
      head_ = nextNode;
    }
    else 
    {
      temp -> next = nullptr; 
      //temp = head_ -> next; 
      //delete head_;
      tail_ = nextNode;
      head_ = nextNode;
    }
    //temp -> next -> prev = nullptr; 

    // temp -> next = nullptr; 
    // temp = head_ -> next; 
    // delete head_;
    // head_ = nextNode; 

  }
}
void ULListStr::pop_back()
{
  tail_->val[tail_ -> last -1] = " ";
  tail_->last = tail_->last - 1;
  size_--;
  
  if(tail_ -> first == tail_ -> last)
  {
    
    Item *temp = tail_;
    Item *prevNode = tail_ -> prev; 
    if(prevNode != nullptr)
    {
      //prevNode -> next = nullptr; 
      temp -> prev -> next = nullptr;
      tail_ -> prev = nullptr;
      delete tail_;
      tail_ = prevNode;
    }
    else {
      tail_ -> prev = nullptr;
      delete tail_;
      tail_ = prevNode;
      head_ = prevNode;
    }
    // tail_ -> prev = nullptr;
    // delete tail_;
    // tail_ = prevNode; 

  }
  
}
void ULListStr::push_front(const std::string& val)
{
  // creates node if does not exist 
  if(head_ == nullptr)
  {
    Item *node = new Item();
    
    node -> val[9] = val;
    node -> prev = nullptr;
    node -> next = nullptr;  
    node -> first = 9;
    node -> last = 10;

    head_ = node;
    tail_ = node; 
    size_++; 
  }
  else 
  {
    if(head_ -> first != 0)
    {
      head_ -> first--;
      head_ -> val[head_->first] = val;
      size_++;
    }
    // if the node is filled 
    // new node and change ptrs
    else 
    {
      Item *node1 = new Item();

      head_ -> prev = node1;

      node1 -> val[9] = val;
      node1 -> prev = nullptr;
      node1 -> next = head_;  
      node1 -> first = 9;
      node1 -> last = 10;

      head_ = node1;
      size_++;
    }
  }
}
void ULListStr::push_back(const std::string& val)
{
  //if empty create new container 
  if(head_ == nullptr)
  {
    Item *node = new Item();
    
    node -> val[0] = val;
    node -> prev = nullptr;
    node -> next = nullptr;  
    node -> first = 0;
    node -> last = 1;

    head_ = node;
    tail_ = node; 
    size_++; 
  }
  //break/b [file.cpp:line number]
  else {

    if(tail_ -> last != 10)
    {
      tail_ -> val[tail_->last] = val;
      tail_ -> last++;
      size_++;
    }
    // if the node is filled 
    // new node and change ptrs
    else 
    {
      Item *node1 = new Item();

      tail_ -> next = node1;

      node1 -> val[0] = val;
      node1 -> prev = tail_;
      node1 -> next = nullptr;  
      node1 -> first = 0;
      node1 -> last = 1;

      tail_ = node1;
      size_++;
    }
  }
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  size_t tempLoc = loc;
  Item* temp = head_;
  std::string* ptr;

  if(loc > size_-1)
  {
    return NULL; 
  }
  
  if(temp -> first != 0)
  {
    tempLoc = temp->first + loc; 
  }

  if(tempLoc < 10)
  {
    //std::string* ptr = &temp->val[loc];
    ptr = &temp->val[tempLoc];
    
  }
  else
  {
    while(tempLoc > 9)
    {
      temp = temp -> next;
      tempLoc = tempLoc - 10;
    }
    ptr = &temp->val[tempLoc];
    
  }
  
  
  
  return ptr;
}
// END OF MY CODE ADDITION

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
