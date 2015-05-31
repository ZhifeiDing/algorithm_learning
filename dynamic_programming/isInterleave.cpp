#include "leetcode.hpp"
/*
 * Given s1, s2, s3, find whether s3 is formed by the interleaving 
 * of s1 and s2.
 * 
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 * 
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 */

/*
 * f[i][j] = ( s3[i+j] == s2[j-1] && f[i][j-1] ) || ( s3[i+j] == s1[i] && f[i-1][j] )
 */
bool isInterleave(string s1, string s2, string s3) {
    if( s3.size() != s1.size() + s2.size() )
        return false;
    vector<vector<bool> > f(s1.size()+1, vector<bool>(s2.size()+1, false));
    for(int i = 1; i <= s1.size(); i++)
      f[i][0] = s1.substr(0,i) == s3.substr(0,i);

    for(int j = 1; j <= s2.size(); j++)
      f[0][j] = s2.substr(0,j) == s3.substr(0,j);

    for(int i = 0; i < s1.size(); i++)
      for( int j = 0; j < s2.size(); j++)
        f[i+1][j+1] = ( f[i+1][j] && s2[j] == s3[i+j+1] ) || ( f[i][j+1] && s1[i] == s3[i+j+1] );
    return f[s1.size()][s2.size()];
}
