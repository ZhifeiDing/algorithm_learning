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
  int m=matrix.size();
  if (m==0) return 0;
  int n=matrix[0].size();
  if (n==0) return 0;
}
