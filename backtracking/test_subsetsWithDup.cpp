#include "leetcode.hpp"

void test_subsetsWithDup() {

  srand((unsigned int)time(NULL));
  int n = rand()%13;
  vector<int> nums;
  gen_array(n, nums);
  print_array(nums);
  vector<vector<int> > r = subsetsWithDup(nums);
  for(int i = 0; i < r.size(); i++)
    print_array(r[i],to_string(i));
  vector<vector<int> > r1 = subsetsWithDup(nums);
  for(int i = 0; i < r1.size(); i++)
    print_array(r1[i],to_string(i));
}
