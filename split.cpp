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

void split(Node*& in, Node*& odds, Node*& evens)
{
  if(in == NULL){
    return;
  }

  else if((in->value)%2==0){
    evens = in;
    split(evens->next, odds, evens->next);
    in = NULL; 
    //in->next = NULL; 
  }

  else{
    odds = in;
    split(odds->next, odds->next, evens);
    in = NULL; 
    //in->next = NULL;
  }

}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE