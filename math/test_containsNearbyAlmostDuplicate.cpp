#include "leetcode.hpp"

void test_containsNearbyAlmostDuplicate() {
  srand((unsigned int)time(NULL));
  int n = rand()%13+1;
  vector<int> nums;
  gen_array(n, nums);
  int k = rand()%n;
  int t = rand()%n;
  print_array(nums);
  string s = containsNearbyAlmostDuplicate(nums, k,t) ? " contains duplicates " : " don't contain duplicates ";
  cout << s << " k = " << k << " t = " << t << endl;
}
