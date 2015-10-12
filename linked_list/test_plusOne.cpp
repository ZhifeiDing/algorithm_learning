#include "leetcode.hpp"

void test_plusOne() {
  srand((unsigned int)time(NULL));
  int n = rand()%7;
  vector<int> digits;
  gen_array(n, digits, 10);
  print_array(digits);
  vector<int> r = plusOne(digits);
  print_array(r);
}
