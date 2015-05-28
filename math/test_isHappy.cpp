#include "leetcode.hpp"

void test_isHappy(void) {
  srand((unsigned int)time(NULL));
  int n = rand() % 91;
  cout << n;
  isHappy(n) ? cout << " is Happy" : cout << " is not happy";
  cout << endl;
}
