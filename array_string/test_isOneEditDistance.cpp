#include "leetcode.hpp"

void test_isOneEditDistance(void) {
  string s,t;
  cout << "Please input first string : ";
  cin.get();
  getline(cin,s);
  cout << "Please input second string : ";
  //cin.get();
  getline(cin,t);
  bool f = isOneEditDistance(s,t);
  if( f ) cout << "True";
  else cout << "False";
  cout << endl;
}

