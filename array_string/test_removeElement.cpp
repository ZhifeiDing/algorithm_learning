#include "leetcode.hpp"

void test_removeElement(void) {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  vector<int> nums;
  gen_array(n, nums);
  print_array(nums);
  int val = rand()%n;
  val = nums[val];
  n = removeElement(nums, val);
  cout << "val = " << val << endl;
  nums.resize(n);
  print_array(nums, "after remove");
}
