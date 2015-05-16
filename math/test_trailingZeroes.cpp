#include "leetcode.hpp"

int nMul(int n) {
  int r = 1;
  while( n > 1 ) {
    r *= n;
    n -= 1;
  }
  return r;
}

void test_trailingZeroes(void) {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  cout << n << "! = " << nMul(n) << " has " << trailingZeroes(n) << " zeroes" << endl;
}
