#include "leetcode.hpp"

void test_divide() {
  srand((unsigned int)time(NULL));
  int dividend = (rand() - rand())%1000;
  int divisor = (rand() - rand())%1000;

  cout << dividend << " / " << divisor << " = " << divide(dividend, divisor) << endl;
  cout << dividend << " / " << divisor << " = " << divide_bs(dividend, divisor) << endl;

}
