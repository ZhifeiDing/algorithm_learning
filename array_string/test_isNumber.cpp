#include "leetcode.hpp"

void test_isNumber(void) {

  string s;
  cout << "Please input a string ( like -123.4as ) :";
  cin.get();
  getline(cin,s);
  cout << "is number " << isNumber(s) << endl;
}
