#include "leetcode.hpp"

void test_summaryRanges( ) {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  vector<int> nums;
  gen_array(n, nums,0,2*n);
  sort(nums.begin(),nums.end());
  print_array(nums);
  vector<string> r = summaryRanges(nums);
  for(int i = 0; i < r.size(); i++)
    cout << r[i] << " ";
  cout << endl;
}
