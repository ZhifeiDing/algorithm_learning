#include "leetcode.hpp"

void print_matrix(vector<vector<int> > & matrix, const string & s = "Matrix") {
  cout << s << " : " << endl;
  int n = matrix.size();
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      cout << matrix[i][j] << "\t";
    cout << endl;
  }
}

void test_rotate() {
  srand((unsigned int)time(NULL));
  int n = rand()%9;
  vector<vector<int> > matrix(n, vector<int>(n));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      matrix[i][j] = rand()%99;
  print_matrix(matrix);
  rotate(matrix);

  print_matrix(matrix, "Rotate");
}

