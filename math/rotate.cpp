#include "leetcode.hpp"
/*
 * You are given an n x n 2D matrix representing an image.
 * 
 * Rotate the image by 90 degrees (clockwise).
 * 
 * Follow up:
 * Could you do this in-place?
 */

void rotate(vector<vector<int> > & matrix) {
  int n = matrix.size();
  if( n < 2 ) return;
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n - i - 1; j++) {
      int t = matrix[i][j];
      matrix[i][j] = matrix[n-j-1][i];
      matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
      matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
      matrix[j][n-i-1] = t;
    }
  }
}
