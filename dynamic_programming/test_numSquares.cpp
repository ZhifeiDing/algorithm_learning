#include "leetcode.hpp"

void test_numSquares() {
  srand((unsigned int)time(NULL));
  int n = rand()%100;
  cout << n << " the least number of perfect squares = " << numSquares(n) << endl;
}
