#include "leetcode.hpp"

void test_wordPattern() {
  string pattern = "abbc";
  string str = "dog big big dig";
  string s = wordPattern(pattern, str) ? " matched " : " not matched ";
  cout << s << endl;

  pattern = "abbc";
  str = "dog dog dog dog";
  s = wordPattern(pattern, str) ? " matched " : " not matched ";
  cout << s << endl;
}
