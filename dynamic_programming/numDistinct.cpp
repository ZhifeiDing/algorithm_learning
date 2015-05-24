#include "leetcode.hpp"
/*
 * Given a string S and a string T, count the number of 
 * distinct subsequences of T in S.
 * 
 * A subsequence of a string is a new string which is formed 
 * from the original string by deleting some (can be none) of 
 * the characters without disturbing the relative positions 
 * of the remaining characters. (ie, "ACE" is a subsequence 
 * of "ABCDE" while "AEC" is not).
 * 
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 * 
 * Return 3.
 */

int numDistinct(string s, string t) {
    // f(i) = s[i] == t[i-1] ? f(i-1) + 1 : f(i-1)
    // f(0) = t[0] == s[0] : 1 ? 0
    int n = s.size();
    int m = t.size();
    if( n == 0 || m == 0 ) return 0;
    vector<int> f(n,0);
    //f[0] = s[0] == t[0] ? 1 : 0;
    for(int i = 0; i < m; i++) {
        for(int j = i; j < n; j++) {
            if( i == j ) {
                f[j] = s[j] == t[i] ? 1 : 0;
            } else {
                f[j] = s[j] == t[i] ? (f[j]*(f[j-1])) : f[j-1];
            }
        }
    }
    return f[n-1];
}
