#include "leetcode.hpp"

void test_nthUglyNumber() {
  srand((unsigned int)time(NULL));
  int n = rand()%20 + 1;
  int r = nthUglyNumber(n);
  cout << n << "th ugly number = " << r << endl;
  r = nthUglyNumber_set(n);
  cout << n << "th ugly number = " << r << endl;
  r = nthUglyNumber_DP(n);
  cout << n << "th ugly number = " << r << endl;
}
