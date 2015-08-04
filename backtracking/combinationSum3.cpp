#include "leetcode.hpp"

/*
 * Find all possible combinations of k numbers that add up to a number n, 
 * given that only numbers from 1 to 9 can be used and each combination 
 * should be a unique set of numbers.
 * 
 * Ensure that numbers within the set are sorted in ascending order.
 * 
 * 
 * Example 1:
 * 
 * Input: k = 3, n = 7
 * 
 * Output:
 * 
 * [[1,2,4]]
 * 
 * Example 2:
 * 
 * Input: k = 3, n = 9
 * 
 * Output:
 * 
 * [[1,2,6], [1,3,5], [2,3,4]]
 */
void combinationSum3Helper(vector<vector<int> > & r, vector<int> & ans, int k, int n, int idx) {
  for(int i = idx; i < 10; i++) {
    if( i > n )
      return;
    if( ans.size() == k - 1 && i == n ) {
      ans.push_back(i);
      r.push_back(ans);
      ans.pop_back();
      return;
    } else if( ans.size() == k - 1 && i < n ) {
      continue;
    }
    ans.push_back(i);
    combinationSum3Helper(r,ans,k,n-i,i+1);
    ans.pop_back();
  }
}

vector<vector<int> > combinationSum3(int k, int n) {
  vector<vector<int> > r;
  vector<int> ans;
  combinationSum3Helper(r, ans, k, n, 1);
  return r;
}
