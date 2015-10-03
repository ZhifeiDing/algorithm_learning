#include "leetcode.hpp"

void test_longestValidParentheses() {
  string s = "(()";
  cout << s << " has " << longestValidParentheses(s) << " parenthese\n";
  cout << s << " has " << longestValidParentheses_twopass(s) << " parenthese\n";
  s = ")()())";
  cout << s << " has " << longestValidParentheses(s) << " parenthese\n";
  s = ")()((()))())";
  cout << s << " has " << longestValidParentheses(s) << " parenthese\n";
  cout << s << " has " << longestValidParentheses_twopass(s) << " parenthese\n";
}
