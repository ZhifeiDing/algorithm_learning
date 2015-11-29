#include "leetcode.hpp"
/*
 * Remove the minimum number of invalid parentheses in order to make the 
 * input string valid. Return all possible results.
 * 
 * Note: The input string may contain letters other than the parentheses ( and ).
 * 
 * Examples:
 * "()())()" -> ["()()()", "(())()"]
 * "(a)())()" -> ["(a)()()", "(a())()"]
 * ")(" -> [""]
 */
void removeInvalidParenthesesHelper(string &s, int left, int right, int idx, string p, unordered_set<string> &r, int &size) {
  if( left == right && idx == s.size() ) {
    if( r.empty() || p.size() == size )
      r.insert(p);
    else if( p.size() > size ) {
      r.erase(r.begin(), r.end());
      r.insert(p);
      size = p.size();
    }
    return;
  }
  for(int i = idx; i < s.size() && right <= left; ++i) {
    if( s[i] == '(' ) {
      removeInvalidParenthesesHelper(s, left, right, i + 1, p, r, size);
      ++left;
      p.push_back(s[i]);
    } else if( s[i] == ')' ) {
      removeInvalidParenthesesHelper(s, left, right, i + 1, p, r, size);
      ++right;
      p.push_back(s[i]);
    } else {
      p.push_back(s[i]);
    }
    if( i == s.size() - 1 )
      removeInvalidParenthesesHelper(s, left, right, i + 1, p, r, size);
  } 
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> r;
    string p;
    unordered_set<string> res;
    int size = 0;
    removeInvalidParenthesesHelper(s, 0, 0, 0, p, res, size);
    for(auto i : res)
      r.push_back(i);
    return r;
}
