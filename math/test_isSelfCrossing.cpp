#include "leetcode.hpp"

void test_isSelfCrossing() {
  srand((unsigned int)time(NULL));
  int n = rand()%13+1;
  vector<int> nums;
  gen_array(n, nums);
  print_array(nums);
  string s = isSelfCrossing(nums) ? " self crossing" : " not self crossing";
  cout << s << endl;
}
