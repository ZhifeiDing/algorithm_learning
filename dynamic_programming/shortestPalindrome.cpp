#include "leetcode.hpp"

/*
 * Given a string S, you are allowed to convert it to a palindrome by 
 * adding characters in front of it. Find and return the shortest 
 * palindrome you can find by performing this transformation.
 * 
 * For example:
 * 
 * Given "aacecaaa", return "aaacecaaa".
 * 
 * Given "abcd", return "dcbabcd".
 */
string shortestPalindrome(string s) {
  if( s.size() == 0 )
    return s;
  string revs = s, l = s + "#";
  reverse(revs.begin(), revs.end());
  l.append(revs);
  vector<int> p(l.size(), 0);
  for(int i = 1; i < l.size(); i++) {
    int j = p[i-1];
    while( j > 0 && l[i] != l[j] )
      j = p[j-1];
    p[i] = j + ( l[i] == l[j] );
  }
  return revs.substr(0, s.size() - p.back()) + s;
}
