#include "leetcode.hpp"

void test_integerBreak() {
  srand((unsigned int)time(NULL));
  int n = rand()%12;
  cout << "integerBreak_DP(" << n << ") = " << integerBreak_DP(n) << endl;
  cout << "integerBreak(" << n << ") = " << integerBreak(n) << endl;
}
