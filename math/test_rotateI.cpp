#include "leetcode.hpp"

void test_rotateI() {
  srand((unsigned int)time(NULL));
  int n = rand() % 11;
  int k = rand() % 11;
  vector<int> nums;
  gen_array(n, nums);
  print_array(nums);
  cout << "After rotate " << k << " : ";
  rotateI(nums,k);
  print_array(nums);
}
