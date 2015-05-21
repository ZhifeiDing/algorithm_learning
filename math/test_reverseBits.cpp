#include "leetcode.hpp"
void test_reverseBits() {
  srand((unsigned int)time(NULL));
  uint32_t n = rand()%101;
  cout << n << " reverse = " << reverseBits(n) << endl;
  cout << n << " reverse = " << reverseBits_lookup(n) << endl;
}
