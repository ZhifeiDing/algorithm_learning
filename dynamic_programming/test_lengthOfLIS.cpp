#include "leetcode.hpp"

void test_lengthOfLIS() {
  srand((unsigned int)time(NULL));
  vector<int> nums;
  int n = rand()%19;
  gen_array(n, nums);
  print_array(nums);
  cout << "length of LIS = " << lengthOfLIS(nums) << endl;
  cout << "length of LIS = " << lengthOfLIS_lowerbound(nums) << endl;
}
