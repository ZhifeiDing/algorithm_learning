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
  vector<int> L(n,0);
  vector<int> R(n,n);
  vector<int> H(n,0);
  int r = 0;
  for(int i = 0; i < m; i++) {
    int left  = 0, right = n;
    for(int j = 0; j < n; j++) {
      if( matrix[i][j] == '1' ) {
        L[j] = max(L[j],left);
        H[j]++;
      } else {
        L[j] = 0;
        R[j] = n;
        H[j] = 0;
        left = j + 1;
      }
    }
    for(int j = n - 1; j >= 0; j--) {
      if( matrix[i][j] == '1' ) {
        R[j] = min(R[j],right);
        r = max(r, H[j] * ( R[j] - L[j] ));
      } else {
        R[j] = n;
        right = j;
      }
    }
  }
  return r;
}
