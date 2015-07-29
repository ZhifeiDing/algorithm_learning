#include "leetcode.hpp"

void test_diffWaysToCompute() {
  string input = "1+3*4-2+1";
  vector<int> r = diffWaysToCompute(input);
  cout << input << " = " << endl;
  print_array(r);
}
