/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */
void helper(Node*& in, Node*& odds, Node*& evens);

void split(Node*& in, Node*& odds, Node*& evens)
{
  helper(in, odds, evens);
  in = NULL;
}

void helper(Node*& in, Node*& odds, Node*& evens){
  if(in == NULL){
    odds->next = NULL;
    evens->next = NULL;
    return;
  }

  else if((in->value)%2==0){
    if(evens==NULL){ //if the first number
      evens=in;
      helper(in->next, odds, evens);
    }
    else{
      evens->next = in;
      helper(in->next, odds, evens->next);
    }
  }

  else{
    if(odds==NULL){ //if first
      odds=in;
      helper(in->next, odds, evens);
    }
    else{
      odds->next = in;
      helper(in->next, odds->next, evens);     
    }

  }
}



/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE