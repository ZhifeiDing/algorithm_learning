#include "leetcode.hpp"
#include "NumMatrix.cpp"

void test_NumMatrix() {
  srand((unsigned int)time(NULL));
  int m = rand()%8;
  int n = rand()%8;
  vector<vector<int> > nums(m);
  for(int i = 0; i < m; ++i) {
    gen_array(n, nums[i], 10);
    print_array(nums[i]);
  }
  int k = rand()%5+1;
  while( --k ) {
    int row1 = rand()%m;
    int row2 = row1 + rand()%(m-row1);

    int col1 = rand()%n;
    int col2 = col1  + rand()%(n-col1);
    NumMatrix numArray(nums);
    cout << "SumRange( (" << row1 << " , " << col1 << "), (" << row2 << " , " << col2 << ") ) = " << numArray.sumRegion(row1,col1,row2,col2) << endl;
  }
}
