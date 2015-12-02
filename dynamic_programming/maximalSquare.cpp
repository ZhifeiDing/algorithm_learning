#include "leetcode.hpp"
/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest 
 * square containing all 1's and return its area.
 * 
 * For example, given the following matrix:
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * Return 4.
 */

int maximalSquare(vector<vector<char> > & matrix) {
  if( matrix.empty() )
    return 0;

  int r = 0;

  for(int i = 0; i < matrix.size(); ++i)
    for(int j = 0; j < matrix[0].size(); ++j) {
      int leftUp = ( i && j ) ? matrix[i-1][j-1] : 0;
      int left   = j ? matrix[i][j-1] : 0;
      int up     = i ? matrix[i-1][j] : 0;

      matrix[i][j] = matrix[i][j] != '0' ? min(leftUp, min(left, up)) + 1 : 0;
      r = max(r, (int)matrix[i][j]);
    }
  return r * r;
}
