#include "leetcode.hpp"

void test_isPowerOfTwo() {
  srand((unsigned int)time(NULL));
  int n = rand()%INT_MAX;
  string s = isPowerOfTwo_online(n) ? " is " : " is not ";
  cout << n << s << "power of two" << endl;
  string r = isPowerOfTwo(n) ? " is " : " is not ";
  cout << n << r << "power of two" << endl;
}
