#include "leetcode.hpp"

void test_isPowerOfFour() {
  int n = 3;
  string r = isPowerOfFour(n) ? " is power of 3" : " is not power of four";
  cout << n << r << endl;
  n = 4;
  r = isPowerOfFour(n) ? " is power of 3" : " is not power of four";
  cout << n << r << endl;
  n = 8;
  r = isPowerOfFour(n) ? " is power of 3" : " is not power of four";
  cout << n << r << endl;
  srand((unsigned int)time(NULL));
  n = rand()/10000;
  r = isPowerOfFour(n) ? " is power of 3" : " is not power of four";
  cout << n << r << endl;
}
