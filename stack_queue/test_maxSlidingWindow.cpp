#include "leetcode.hpp"

void test_maxSlidingWindow() {
  srand((unsigned int)time(NULL));
  int n = rand()%13 + 1;
  int k = rand()%n;
  vector<int> nums;
  gen_array(n,nums);
  print_array(nums);
  cout << "max sliding " << k << " : ";
  vector<int> r = maxSlidingWindow(nums,k);
  print_array(r);
}
