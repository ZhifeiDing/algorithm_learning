#include "leetcode.hpp"

void test_atoi(void) {

  string s;
  cout << "Please input a string ( like -1234as ) :";
  cin.get();
  getline(cin,s);
  cout << "Converted integeral : " << atoi(s) << endl;
}

