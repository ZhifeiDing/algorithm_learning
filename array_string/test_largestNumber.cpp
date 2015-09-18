#include "leetcode.hpp"

void test_largestNumber() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  vector<int> nums;
  gen_array(n, nums);
  print_array(nums);

  cout << "the largest number = " << largestNumber(nums) << endl;
}

