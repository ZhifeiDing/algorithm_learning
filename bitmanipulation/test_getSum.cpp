#include "leetcode.hpp"

void test_getSum() {
  srand((unsigned int)time(NULL));
  int a = rand() % 20;
  int b = rand() % 20;
  cout << "getSum(" << a << " , " << b << ") = " << getSum(a,b) << endl;
}
