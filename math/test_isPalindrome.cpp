#include "leetcode.hpp"

void test_isPalindrome() {
  srand((unsigned int)time(NULL));
  int x = rand();
  string s = isPalindrome(x) ? " is Palindrome" : " is not Palindrome";
  cout << x << s << endl;
}
