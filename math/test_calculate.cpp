#include "leetcode.hpp"

void test_calculate(void) {
  string s = "1-1";
  cout << s << " = " << calculate(s) << endl;
  string s1 = "1 - ( 1 + (  2 - 1 ) - 2 + ( 2 +1))";
  cout << s1 << " = " << calculate(s1) << endl;
}
