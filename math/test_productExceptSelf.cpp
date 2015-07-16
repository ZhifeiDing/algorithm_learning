#include "leetcode.hpp"

void test_productExceptSelf() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  vector<int> nums;
  gen_array(n,nums, 9);
  print_array(nums);
  vector<int> r = productExceptSelf(nums);
  print_array(r);
}
