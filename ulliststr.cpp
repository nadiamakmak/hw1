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
void ULListStr::push_back(const std::string& val){ //adding at the end

  //THREE CASES: 1) entire list is empty; 2) tail has no space; 3) tail has space

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
void ULListStr::push_front(const std::string& val){ //adding at the beginning

  //THREE CASES: 1) entire list is empty; 2) head is full; 3) head has space AT THE BEGINNING

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
void ULListStr::pop_back(){ //removing at the end

  //FOUR CASES: 1) list is empty; 2) one number in tail AND only one item total; 2) one number in tail; 4) more than one number in tail

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

void ULListStr::pop_front(){ //removing at the beginning

  //FOUR CASES: 1) list is empty; 2) one number in head AND only one item total; 2) one number in head; 4) more than one number in head

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
std::string const & ULListStr::back() const{ //access last
  if(size_==0){ throw std::invalid_argument("\n ERROR: Location does not exist. Terminating. \n"); }
  return tail_->val[(tail_->last)-1];
}

std::string const & ULListStr::front() const{ //access first 
  if(size_==0){ throw std::invalid_argument("\n ERROR: Location does not exist. Terminating. \n"); }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{ //get val

  if(loc < 0 || loc >= size_){ //checking to see if location exists
    throw std::invalid_argument("\n ERROR: Location does not exist. Terminating. \n");
  }

  Item* currentItem = head_;
  size_t placeInItem, placeInList;

  placeInList = 0;
  placeInItem = head_->first; //start at the beginning

  while(placeInList != loc){
    placeInItem++;
    placeInList++;
    if(placeInItem==currentItem->last){ //need to move on to the next item
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
