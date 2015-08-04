#include "leetcode.hpp"

void test_findKthLargest() {
  srand((unsigned int)time(NULL));
  int n = rand()%13 + 1;
  int k = rand()%n + 1;
  vector<int> nums;
  gen_array(n, nums);
  print_array(nums);
  int r = findKthLargest(nums, k);
  cout << k << "th largest = " << r << endl;
  print_array(nums);
}
