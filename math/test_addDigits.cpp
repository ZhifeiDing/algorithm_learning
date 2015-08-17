#include "leetcode.hpp"

void test_addDigits() {
  srand((unsigned int)time(NULL));
  int num = rand() % INT_MAX;
  int r = addDigits(num);
  cout << "digital_roor(" << num << ") = " << r << endl;
}
