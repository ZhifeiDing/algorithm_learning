#include "leetcode.hpp"

void test_maximalSquare() {
  srand((unsigned int)time(NULL));
  int m = rand()%8;
  int n = rand()%8;
  vector<vector<char> > matrix(m, vector<char>(n));
  for(int i = 0; i < m; i++) 
    for(int j = 0; j < n; j++) 
      matrix[i][j] = rand()%2 + '0';
  for(int i =  0; i < m; i++) {
    for(int j = 0; j < n; j++)
      cout << matrix[i][j] << "\t";
    cout << endl;
  }
  cout << " maximal square : " << maximalSquare(matrix) << endl;
}
