#include "leetcode.hpp"

/*
 * Given a string containing just the characters '(' and ')', 
 * find the length of the longest valid (well-formed) parentheses 
 * substring.
 * 
 * For "(()", the longest valid parentheses substring is "()", which 
 * has length = 2.
 * 
 * Another example is ")()())", where the longest valid parentheses 
 * substring is "()()", which has length = 4.
 */

// dynamic solution 
// f[i] = s[i] == ')' ? s[i-1] == '(' ? f[i-2] + 2 : s[i-f[i-1]-1] == '(' ? f[i-f[i-1]-2] + 2 + f[i-1]
int longestValidParentheses(string s) {
  vector<int> f(s.size(),0);
  int longest = 0;
  for(int i = 1; i < s.size();i++) {
    if( s[i] == ')' ) {
      if( s[i-1] == '(' ) {
        f[i] = f[i-2] + 2;
      } else if( 0 <= i - f[i-1] - 1 && s[i-f[i-1]-1] == '(' ) {
        f[i] = f[i-1] + 2 + ( 0 <= i - f[i-1] - 2 ? f[i-f[i-1]-2] : 0 );
      }
    }
    longest = max(longest, f[i]);
  }
  return longest;
}
