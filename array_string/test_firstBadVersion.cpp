#include "leetcode.hpp"

void test_firstBadVersion() {
  srand((unsigned int)time(NULL));
  int n = rand() % 1000;
  int r = firstBadVersion(n);
  cout << "first bad version of " << n << " = " << r << endl;
}
