#include "leetcode.hpp"

void test_mySqrt() {
  srand((unsigned int)time(NULL));
  int x = rand();
  cout << "sqrt( " << x << " ) = " << mySqrt(x) << endl;
  cout << "sqrt( " << x << " ) = " << sqrt(x) << endl;
}
