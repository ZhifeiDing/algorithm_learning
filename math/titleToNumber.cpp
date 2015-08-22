#include "leetcode.hpp"
/*
 * Related to question Excel Sheet Column Title
 * 
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * 
 * For example:
 * 
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28
 */
int titleToNumber(string s) {
  int r = 0;
  for(auto i : s)
    r = r * 26 + ( i - 'A' + 1 );
  return r;
}
