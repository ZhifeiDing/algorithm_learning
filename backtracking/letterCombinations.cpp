#include "leetcode.hpp"

/*
 * Given a digit string, return all possible letter combinations that 
 * the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is 
 * given below.
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

// non-recursive solution
vector<string> numMap = {" ", "@", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> letterCombinations(string digits) {
  vector<string> r;
  int size = 0;
  for(auto i : digits) {
    size = r.size();
    string s = numMap[i-'0'];
    for(int j = 0; j < s.size(); ++j) {
      if( size == 0 ) {
        r.push_back(string(1,s[j]));
      } else {
        for(int k = 0; k < size; ++k) {
          if( j == s.size() - 1 ) {
            r[k].push_back(s[j]);
          } else {
            string t = r[k];
            t.push_back(s[j]);
            r.push_back(t);
          }
        }
      }
    }
  }
  return r;
}
