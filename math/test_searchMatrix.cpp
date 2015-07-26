#include "leetcode.hpp"

void test_searchMatrix() {
  srand((unsigned int)time(NULL));
  int n = rand()%9;
  int m = rand()%6;
  vector<vector<int> > matrix(m, vector<int>(n));
  for(int i = 0; i < m; i++) 
    for(int j = 0; j < n; j++)
      matrix[i][j] = rand()%99;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++)
      cout << matrix[i][j] << "\t";
    cout << endl;
  }
  int target = rand() % 99;
  string s = searchMatrix(matrix, target) ? " Found " : " Didn't find ";
  cout << s << target << endl;
}

