#include "leetcode.hpp"

/*
 * Given two binary strings, return their sum (also a binary string).
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */

string addBinary(string a, string b) {
  string s;
  int i = 0;
  int next = 0;
  while( i < min(a.size(), b.size()) ) {
    int val = (a[a.size()-i-1] - '0') + (b[b.size()-i-1] - '0') + next;
    if( val == 3 ) {
      s.push_back('1');
      next = 1;
    } else if( val == 2 ) {
      s.push_back('0');
      next = 1;
    } else {
      s.push_back(val + '0');
      next = 0;
    }
    ++i;
  }
  if( a.size() < b.size() )
    a = b;
  while( i < a.size() ) {
    int val = (a[a.size()-i-1] - '0') + next;
    if( val == 2 ) {
      s.push_back('0');
      next = 1;
    } else {
      s.push_back(val + '0');
      next = 0;
    }
    ++i;
  }
  if( next )
    s.push_back('1');
  reverse(s.begin(),s.end());
  return s;
}
