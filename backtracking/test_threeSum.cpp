#include "leetcode.hpp"

void test_threeSum(void) {
  //int A[] = {3,0,-2,-1,1,2};
  int A[] = {-15,10,0,-2,14,-1,-10,-14,10,12,6,-6,10,2,-11,-9,2,13,2,-9,-14,-12,-10,-12,13,13,-10,-3,2,-11,3,-6,6,10,7,5,-13,4,-2,12,1,-11,14,-4,6,-12,-6,-14,8,11,-8,1,7,-3,5,5,-13,10,9,-3,6,-10,6,-3,7,-9,-13,9,10,0,-1,-11,4,-10,-8,-13,-15,2,-12,8,-2,-12,-14,-10,-8,6,2,-5,-7,-11,7,14,-6,-10,-12,8,-4,-10,-5,14,-3,9,-12,8,14,-13};
  vector<int> nums(A, A + sizeof(A)/sizeof(int));
  vector<vector<int> > r = threeSum(nums);
  for(int i = 0; i < r.size(); i++) {
    for(int j = 0; j < r[i].size(); j++)
      cout << r[i][j] << "\t";
    cout << endl;
  }
  cout << endl;

  r = threeSum_twoPointers(nums);
  for(int i = 0; i < r.size(); i++) {
    for(int j = 0; j < r[i].size(); j++)
      cout << r[i][j] << "\t";
    cout << endl;
  }
  cout << endl;
}

