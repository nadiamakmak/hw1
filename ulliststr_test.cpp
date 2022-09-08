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
  dat.push_back("3");
  dat.push_back("3");
  cout << dat.get(0) << " " << dat.get(1) << dat.get(2) << endl;
  // prints: 8 7 9
  cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
  return 0;
}
