#include "leetcode.hpp"

void test_merge() {
  srand((unsigned int)time(NULL));

  int m = rand() % 11;
  int n = rand() % 11;

  vector<int> nums1, nums2;
  gen_array(m, nums1);
  gen_array(n, nums2);
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  print_array(nums1, "nums1");
  print_array(nums2, "nums2");
  nums1.resize(m+n);
  merge(nums1,m,nums2,n);
  print_array(nums1, "after merge");
}
