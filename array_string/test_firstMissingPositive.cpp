#include "leetcode.hpp"

void test_firstMissingPositive() {
  srand((unsigned int)time(NULL));
  int n = rand()%13;
  vector<int> nums;
  gen_array(n, nums, -2, 10);
  print_array(nums);
  int r = firstMissingPositive(nums);
  cout << "first missing positive = " << r << endl;
}
