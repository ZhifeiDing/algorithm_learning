#include "leetcode.hpp"

void test_isPowerOfThree() {
  int n = 3;
  string r = isPowerOfThree(n) ? " is power of 3" : " is not power of three";
  cout << n << r << endl;
  n = 2;
  r = isPowerOfThree(n) ? " is power of 3" : " is not power of three";
  cout << n << r << endl;
  n = 27;
  r = isPowerOfThree(n) ? " is power of 3" : " is not power of three";
  cout << n << r << endl;
  srand((unsigned int)time(NULL));
  n = rand()/10000;
  r = isPowerOfThree(n) ? " is power of 3" : " is not power of three";
  cout << n << r << endl;
}
