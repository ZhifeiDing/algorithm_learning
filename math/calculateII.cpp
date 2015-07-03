#include "leetcode.hpp"
/*
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, 
 * +, -, *, / operators and empty spaces . The integer division should 
 * truncate toward zero.
 * 
 * You may assume that the given expression is always valid.
 * 
 * Some examples:
 * "3+2*2" = 7
 * " 3/2 " = 1
 * " 3+5 / 2 " = 5
 * Note: Do not use the eval built-in library function.
 */
int calculateII(string s) {
  int r = 0, cur = 0;
  char op = '+';
  for(int idx = s.find_first_not_of(' '); idx < s.size(); idx = s.find_first_not_of(' ', idx)) {
    if( s[idx] >= '0' && s[idx] <= '9' ) {
      int t = s[idx] - '0';
      while( s[++idx] >= '0' && s[idx] <= '9' )
        t = t * 10 + ( s[idx] - '0' );
      switch(op) {
        case '+': cur += t; break;
        case '-': cur -= t; break;
        case '*': cur *= t; break;
        case '/': cur /= t; break;
      }
    } else {
      op = s[idx++];
      if( op == '+' || op == '-' ) {
        r += cur;
        cur = 0;
      }
    }
  }
  return r + cur;
}
