#include "leetcode.hpp"

class NumMatrix {
public:
NumMatrix(vector<vector<int>> &matrix) {
  nums = new vector<vector<int> >(matrix.size() + 2, vector<int>(matrix[0].size() + 2, 0));
  
  for(int i = 0; i < matrix.size(); ++i) {
    for(int j = 0; j < matrix[0].size(); ++j) {
      (*nums)[i+1][j+1] = (*nums)[i+1][j] + (*nums)[i][j+1] - (*nums)[i][j] + matrix[i][j];
    }
  }
}

int sumRegion(int row1, int col1, int row2, int col2) {

  return (*nums)[row2+1][col2+1] - (*nums)[row2+1][col1] - (*nums)[row1][col2+1] + (*nums)[row1][col1];

}

private:

  vector<vector<int> > *nums;

};
