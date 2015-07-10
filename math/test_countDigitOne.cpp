#include "leetcode.hpp"

void test_countDigitOne() {
  srand((unsigned int)time(NULL));
  int n = rand();
  cout << n << " contains " << countDigitOne(n) << " one" << endl;
}
