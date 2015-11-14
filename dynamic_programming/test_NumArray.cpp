#include "leetcode.hpp"
#include "NumArray.cpp"

void test_NumArray() {
  srand((unsigned int)time(NULL));
  int n = rand()%12;
  vector<int> nums;
  gen_array(n, nums);
  print_array(nums);
  int m = rand()%5+1;
  while( --m ) {
    int i = rand()%n;
    int j = i + rand()%(n-i);
    NumArray numArray(nums);
    cout << "Sum(" << i << " , " << j << ") = " << numArray.sumRange(i,j) << endl;
  }
}
