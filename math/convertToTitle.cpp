#include "leetcode.hpp"

/*
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * 
 * For example:
 * 
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB
 */
string convertToTitle(int n) {
  string s;
  while( n ) {
    s.push_back((n-1)%26 + 'A');
    n = (n-1)/26;
  }
  reverse(s.begin(),s.end());
  return s;
}
