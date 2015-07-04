#include "leetcode.hpp"

void test_majorityElement() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  vector<int> nums;
  gen_array(n, nums, n);
  print_array(nums);
  vector<int> r = majorityElement(nums);
  print_array(r);
}
