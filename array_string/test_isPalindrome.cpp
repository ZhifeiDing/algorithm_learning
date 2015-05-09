#include "leetcode.hpp"

void test_isPalindrome(void) {
  string s;
  srand((unsigned int)time(NULL));
  int n = rand() % 13;
  gen_string(s,n);
  print_string(s);
  cout << isPalindrome(s) << endl;
}
