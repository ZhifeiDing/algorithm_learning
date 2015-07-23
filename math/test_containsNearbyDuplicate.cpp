#include "leetcode.hpp"

void test_containsNearbyDuplicate() {
  srand((unsigned int)time(NULL));
  int n = rand()%13+1;
  vector<int> nums;
  gen_array(n, nums);
  int k = rand()%n;
  print_array(nums);
  string s = containsNearbyDuplicate(nums, k) ? " contains duplicates " : " don't contain duplicates ";
  cout << s << k << endl;
}

