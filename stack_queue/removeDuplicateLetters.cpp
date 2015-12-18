#include "leetcode.hpp"

/*
 * Given a string which contains only lowercase letters, 
 * remove duplicate letters so that every letter appear 
 * once and only once. You must make sure your result is 
 * the smallest in lexicographical order among all possible 
 * results.
 * 
 * Example:
 * Given "bcabc"
 * Return "abc"
 * 
 * Given "cbacdcbc"
 * Return "acdb"
 */

string removeDuplicateLetters(string s) {
  vector<int> cnt(26,0);
  string r;
  vector<bool> isPushed(26,false);
  for(auto c : s)
    ++cnt[c - 'a'];

  for(auto c : s) {
    --cnt[c-'a'];
    if( r.empty() ) {
      r.push_back(c);
      isPushed[c-'a'] = true;
    }
    if( isPushed[c-'a'] )
      continue;
    while( c < r.back() && !r.empty() && cnt[r.back()-'a'] ) {
      isPushed[r.back()-'a'] = false;
      r.pop_back();
    }
    r.push_back(c);
    isPushed[c-'a'] = true;
  }
  return r;
}
