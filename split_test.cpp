#include "split.h"
#include <iostream>
#include <cstddef>
using namespace std;

void print(Node* cur){
  if (cur == NULL){
    cout << "none" << endl;
    return;
  }
  else{
    cout << cur->value << " ";
  }
  print(cur->next);
}

void deleter2(Node* cur){
  if (cur == NULL){
    return;
  }
  else{
    deleter2(cur->next);
    delete cur;
    //cur = NULL;
  }
}

int main(){
  /*Node* test1 = new Node(2, new Node(4, new Node(7, new Node(11, new Node(12, NULL)))));

  cout << "test case: ";
  print(test1);

  Node* o = NULL;
  Node* e = NULL;
  
  split(test1, o, e);

  cout << "odds: ";
  print(o);
  cout << "evens: ";
  print(e);
  cout << "original list is now: ";
  print(test1);

  deleter2(test1);
  deleter2(o);
  deleter2(e);

  cout <<"deleting..." << endl;

  cout << "odds: ";
  print(o);
  cout << "evens: ";
  print(e);
  cout << "original list is now: ";
  print(test1);

  return 0;*/
}

