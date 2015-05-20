#include "leetcode.hpp"

void test_solveNQueens(void) {
  srand((unsigned int)time(NULL));
  int n = rand() % 11;
  vector<vector<string> > r = solveNQueens(n);
  for(int i = 0; i < r.size(); i++) {
    cout << "Solution :" << endl;
    for(int j = 0; j < n; j++)
      cout << r[i][j] << endl;
  }
}

