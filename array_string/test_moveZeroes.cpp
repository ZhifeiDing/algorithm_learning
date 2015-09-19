#include "leetcode.hpp"

void test_moveZeroes() {
  srand((unsigned int)time(NULL));
  int n = rand()%13;
  vector<int> nums;
  gen_array(n, nums, 0, 12);
  print_array(nums);
  moveZeroes(nums);
  print_array(nums);
}
