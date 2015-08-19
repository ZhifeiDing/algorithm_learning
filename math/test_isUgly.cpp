#include "leetcode.hpp"

void test_isUgly() {
  srand((unsigned int)time(NULL));
  int num = rand()%200;
  string s = isUgly(num) ? " ugly number " : " not ugly number";
  cout << num << " is " << s << endl;
}
