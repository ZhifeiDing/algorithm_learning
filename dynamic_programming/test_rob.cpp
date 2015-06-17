#include "leetcode.hpp"

void test_rob() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  vector<int> nums;
  gen_array(n, nums);
  int r = rob(nums);
  print_array(nums);
  cout << "max rob = " << r << endl;
}
