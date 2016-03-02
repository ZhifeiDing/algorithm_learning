#include "leetcode.hpp"

void test_longestIncreasingPath() {

  srand((unsigned int)time(NULL));
  int m = rand()%10;
  int n = rand()%10;
  vector<vector<int> > matrix(m, vector<int>(n));
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      matrix[i][j] = rand()%20;
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
  int r = longestIncreasingPath(matrix);
  cout << "longest increasing path = " << r << endl;
  cout << "longest increasing path = " << longestIncreasingPath_lambda(matrix) << endl;

}
