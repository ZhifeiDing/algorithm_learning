#include "leetcode.hpp"

int maximalSquare(vector<vector<char> > & matrix) {
  int m=matrix.length;
  if (m==0) return 0;
  int n=matrix[0].length;
  if (n==0) return 0;
  vector<vector<int> > left(m, vector<int>(n)), top(m,vector<int>(n)), val(m,vector<int>(n));
  for (int i=0;i<m;i++) {
       left[i][0]=matrix[i][0]-'0';
       for(int j=1;j<n;j++)
           left[i][j]=matrix[i][j]=='1'?left[i][j-1]+1:0;
  }
  for(int j=0;j<n;j++) {
       top[0][j]=matrix[0][j]-'0';
       for (int i=1;i<m;i++)
          top[i][j]=matrix[i][j]=='1'?top[i-1][j]+1:0;
  }
  int ans = 0;
  for (int i=0;i<m;i++)
      for (int j=0;j<n;j++) {
          int min=Math.min(left[i][j], top[i][j]);
          val[i][j]=i*j==0?min:Math.min(min, val[i-1][j-1]+1);
          if (ans<val[i][j]) ans=val[i][j];
      }
  return ans*ans;
}
