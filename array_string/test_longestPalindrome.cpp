#include "leetcode.hpp"
void test_longestPalindrome(void) {
  string s;
  cout << "Input a string : ";
  cin.get();
  getline(cin, s);
  string r = longestPalindrome(s);
  cout << "Longest Palindrome is : ";
  print_string(r);
}
