#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"
using namespace std;

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
void ULListStr::push_back(const std::string& val){

  if(empty()==true){
    Item *firstItem = new Item();
    tail_ = firstItem, head_ = firstItem;
    firstItem->val[firstItem->last] = val;
    firstItem->last = (firstItem->last)+1;
    size_ = size_ + 1;
  }

  else if(tail_->last==ARRSIZE){
    Item *newLast = new Item();
    newLast->prev = tail_;
    tail_->next = newLast;
    tail_ = newLast;
    tail_->val[tail_->last] = val;
    tail_->last = (tail_->last)+1;
    size_ = size_ + 1;
  }

  else if(tail_->last!=ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last = (tail_->last) + 1;
    size_ = size_ + 1;
  }  

}

void ULListStr::push_front(const std::string& val){ 

  if(empty()==true){
    Item *firstItem = new Item();
    head_ = firstItem, tail_ = firstItem;
    firstItem->val[firstItem->first+(ARRSIZE-1)] = val;
    firstItem->last = ARRSIZE;
    firstItem->first = ARRSIZE-1;
    size_ = size_ + 1;
  }

  else if(head_->first == 0){
    Item *newFirst = new Item();
    newFirst->next = head_;
    head_->prev = newFirst;
    head_ = newFirst;
    head_->val[ARRSIZE-1] = val;
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
    size_ = size_ + 1;
  }

  else if(head_->first != 0){
    head_->val[(head_->first)-1] = val;
    head_->first = (head_->first)-1;
    size_ = size_ + 1;
  }

}
void ULListStr::pop_back(){ 

  if(empty()==true){
    return;
  }

  else if(tail_->last==1 && tail_== head_){
    delete tail_;
    tail_ = nullptr, head_ = nullptr;
    size_ = size_ - 1;
  }

  else if(tail_->last==1){
    tail_ = tail_->prev;
    delete tail_->next;
    tail_->next = nullptr;
    size_ = size_ - 1;
  }

  else if(tail_->last>1){
    tail_->last = tail_->last - 1;
    size_ = size_ - 1;
  }

}

void ULListStr::pop_front(){ 

  if(empty()==true){
    return;
  }

  else if(head_->first==ARRSIZE-1 && head_==tail_){
    delete head_;
    head_ = nullptr, head_ = nullptr;
    size_ = size_ - 1;
  }

  else if(head_->first==ARRSIZE-1){
    head_=head_->next;
    delete head_->prev;
    head_->prev = nullptr;
    size_ = size_ - 1;
  }

  else if(head_->first!=ARRSIZE-1){
    head_->first = head_->first + 1;
    size_ = size_ - 1;
  }

}

std::string const & ULListStr::back() const{ 
  return tail_->val[(tail_->last)-1];
}

std::string const & ULListStr::front() const{ 
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{

  if(int(loc) <= -1 || loc >= size_){
    return nullptr;
  }

  Item* currentItem = head_;
  size_t placeInItem, placeInList;

  placeInList = 0;
  placeInItem = head_->first;

  while(placeInList != loc){
    placeInItem++;
    placeInList++;
    if(placeInItem==currentItem->last){
      currentItem = currentItem->next;
      placeInItem = currentItem->first;
    }
  }
  return &currentItem->val[placeInItem];

}

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
