#include "leetcode.hpp"

void test_shortestPalindrome() {
  srand((unsigned int)time(NULL));
  int n = rand()%9;
  string s;
  gen_string(s,n, true);
  cout << "Original : " << s << endl;
  string r = shortestPalindrome(s);
  cout << "Shortest Palindrome : " << r << endl;
}
