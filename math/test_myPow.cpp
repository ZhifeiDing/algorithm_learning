#include "leetcode.hpp"

void test_myPow() {
  int n = INT_MIN;
  double x = 1.000;
  cout << "pow(" << x << " , " << n << " ) = " << myPow(x,n) << endl;
  n = rand();
  x = rand();
  cout << "pow(" << x << " , " << n << " ) = " << myPow(x,n) << endl;
}
