/* Write your test code for the ULListStr in this file */

#include "ulliststr.h"
#include <iostream>
#include <cstddef>
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("7");
  dat.push_back("9");
  dat.push_front("3");
  dat.pop_back();
  dat.pop_front();
  dat.push_back("23");
  dat.push_back("2");
  dat.pop_back();
  dat.push_back("12");
  dat.pop_front();
  dat.pop_front();
  dat.push_back("4");
  dat.push_front("8");
  dat.pop_back();
  dat.pop_front();
  dat.push_back("3");
  dat.push_back("6");
  dat.push_front("7");
  dat.push_back("3");

  size_t counter = 0;
  cout << "list: ";
  while(counter<dat.size()){
    cout << dat.get(counter) << " ";
    counter++;
  }

  cout << endl << "first item in the entire list: " << dat.front() << endl;
  cout << "last item in the entire list: " << dat.back() << endl;
  cout << "size: " << dat.size() << endl;

  return 0;
}
