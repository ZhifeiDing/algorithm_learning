#include "leetcode.hpp"

void test_sortColors() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  vector<int> nums1;
  gen_array(n, nums1,3);
  print_array(nums1);
  sortColors(nums1);
  print_array(nums1, "Sorted");
}
