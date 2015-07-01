#include "leetcode.hpp"

void test_countPrimes() {
  srand((unsigned int)time(NULL));
  int n = rand()%10000000;
  cout << "countPrimes(" << n << ") = " << countPrimes(n) << endl;
}
