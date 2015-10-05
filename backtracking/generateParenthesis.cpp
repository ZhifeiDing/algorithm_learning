#include "leetcode.hpp"

/*
 * Given n pairs of parentheses, write a function to generate 
 * all combinations of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * 
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */

void generateParenthesisHelper(unordered_set<string> & r, string s, int & n, int rh , int l) {
  if( s.size() == 2 * n && rh == l ) {
    r.insert(s);
    return;
  }

  for(int i = 1; s.size() < 2 * n && l <= rh && rh <= n && i < n + 1; ++i) {
    generateParenthesisHelper(r, s + string(i, '('), n, rh + i, l);
    if( l < rh )
      generateParenthesisHelper(r, s + string(i, ')'), n, rh, l+i);
  }
}

vector<string> generateParenthesis(int n) {
  unordered_set<string> r;
  string s;
  generateParenthesisHelper(r, s, n, 0, 0);
  vector<string> res;
  for(auto i : r)
    res.push_back(i);
  return res;
}
