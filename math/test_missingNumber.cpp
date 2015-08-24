#include "leetcode.hpp"

void test_missingNumber() {
  srand((unsigned int)time(NULL));
  int n = rand()%13;
  int k = rand()%(n+1);
  vector<int> nums;
  for(int i = 0; i < n; i++) {
      nums.push_back(i);
    if( i == k )
      i = i + 1;
  }
  print_array(nums);
  int r = missingNumber(nums);
  cout << "Missing = " << r << endl;
}
