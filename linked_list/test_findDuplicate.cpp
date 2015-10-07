#include "leetcode.hpp"

void test_findDuplicate() {
  srand((unsigned int)time(NULL));
  vector<int> nums;
  int n = rand()%10+2;
  for(int i = 1; i <= n; ++i)
    nums.push_back(i);
  nums.push_back(rand()%n+1);
  print_array(nums);
  int r = findDuplicate(nums);
  cout << "duplicate = " << r << endl;
  cout << "duplicate = " << findDuplicate_bs(nums) << endl;
  cout << "duplicate = " << findDuplicate_bit(nums) << endl;
}

