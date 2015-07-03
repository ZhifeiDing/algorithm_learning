#include"leetcode.hpp"

void test_calculateII() {
  string s = " 2 * 3 - 4 / 3 + 1 ";
  cout << s << " = " << calculateII(s) <<endl;
  string r = " 3 - 4 + 2 * 1 /4 ";
  cout << r << " = " << calculateII(r) <<endl;
}
