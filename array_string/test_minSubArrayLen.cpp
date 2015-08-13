#include "leetcode.hpp"

void test_minSubArrayLen() {
  srand((unsigned int)time(NULL));
  int n = rand()%200;
  vector<int> nums;
  gen_array(n, nums);
  print_array(nums);
  int s = rand()%11;
  cout << "Minimum length of " << s << " = " << minSubArrayLen(s,nums) << endl;
}
