#include "leetcode.hpp"

void test_threeSumClosest() {
  srand((unsigned int)time(NULL));
  int n = rand()%12 + 3;
  int target = rand()%100;
  vector<int> nums;
  gen_array(n, nums);
  print_array(nums);
  cout << "closest target to " << target << " = " << threeSumClosest(nums, target) << endl;
}
