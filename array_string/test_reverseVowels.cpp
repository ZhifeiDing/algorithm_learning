#include "leetcode.hpp"

void test_reverseVowels() {
  srand((unsigned int)time(NULL));
  int n = rand() % 7;
  string s;
  int i = 0;
  gen_string(s, rand() % 7 + 1);
  cout << "reverseVowels(" << s << ") = " << reverseVowels(s) << endl;
}
