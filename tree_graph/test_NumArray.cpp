#include "leetcode.hpp"
#include "NumArray.cpp"

void test_NumArray() {
  srand((unsigned int)time(NULL));
  int n = rand()%12;
  vector<int> nums;
  gen_array(n, nums);
  print_array(nums);
  int m = rand()%5+1;
  NumArray numArray(nums);
  while( --m ) {
    int i = rand()%n;
    int j = i + rand()%(n-i);
    cout << "Sum(" << i << " , " << j << ") = " << numArray.sumRange(i,j) << endl;

    int val = rand()%100;
    nums[i] = val;
    numArray.update(i,val);
    cout << "Modify nums : ";
    print_array(nums);
    cout << "Sum(" << i << " , " << j << ") = " << numArray.sumRange(i,j) << endl;
  }
  cout << "Binary Index Tree: " << endl;
  m = rand()%5+1;
  NumArray_BIT numArray(nums);
  while( --m ) {
    int i = rand()%n;
    int j = i + rand()%(n-i);
    cout << "Sum(" << i << " , " << j << ") = " << numArray.sumRange(i,j) << endl;

    int val = rand()%100;
    nums[i] = val;
    numArray.update(i,val);
    cout << "Modify nums : ";
    print_array(nums);
    cout << "Sum(" << i << " , " << j << ") = " << numArray.sumRange(i,j) << endl;
  }
}
