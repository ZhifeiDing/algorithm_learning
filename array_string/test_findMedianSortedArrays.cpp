#include "leetcode.hpp"

void test_findMedianSortedArrays() {
  srand((unsigned int)time(NULL));
  int n1 = rand()%11;
  int n2 = rand()%11;
  vector<int> nums1, nums2;
  gen_array(n1, nums1);
  gen_array(n2, nums2);
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  print_array(nums1);
  print_array(nums2);
  double r = findMedianSortedArrays(nums1, nums2);
  cout << "Median = " << r << endl;
}
