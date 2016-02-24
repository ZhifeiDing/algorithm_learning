#include "leetcode.hpp"

void test_minPatches() {
  srand((unsigned int)time(NULL));
  int n1 = rand()%11;
  int n2 = rand()%111 + 8;
  vector<int> nums1;
  gen_array(n1, nums1,10);
  print_array(nums1);
  int r = minPatches(nums1, n2);
  cout << "n = " << n2 << "\tmin patches = " << r << endl;
}
