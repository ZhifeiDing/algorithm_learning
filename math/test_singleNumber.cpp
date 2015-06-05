#include "leetcode.hpp"

void test_singleNumber() {
  srand((unsigned int)time(NULL));
  int n = rand()%5 + 1;
  vector<int> nums;
  gen_array(n, nums);
  nums.resize(2*n+1);
  copy(nums.begin(),nums.begin()+n, nums.begin()+n);
  nums[2*n] = rand()%11;
  print_array(nums);
  int r = singleNumber(nums);
  cout << "Single Value: " << r << endl;
}
  
