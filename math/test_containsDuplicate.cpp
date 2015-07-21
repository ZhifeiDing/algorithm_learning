#include "leetcode.hpp"

void test_containsDuplicate() {
  srand((unsigned int)time(NULL));
  int n = rand()%13+1;
  vector<int> nums;
  gen_array(n, nums);
  print_array(nums);
  string s = containsDuplicate(nums) ? " contains duplicates " : " don't contain duplicates ";
  cout << s << endl;
}
