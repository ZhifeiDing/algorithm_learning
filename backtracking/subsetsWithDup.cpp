#include "leetcode.hpp"

/*
 * Given a collection of integers that might contain duplicates, nums, return all 
 * possible subsets.
 * 
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,2], a solution is:
 * 
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 */

void subsetsWithDupHelper(vector<int>& nums, int start, vector<vector<int> > & r, vector<int> & s) {
  for(int i = start; i < nums.size(); i++) {
      if( i == start || nums[i] != nums[i-1] ) {
        s.push_back(nums[i]);
        r.push_back(s);
        subsetsWithDupHelper(nums, i+1, r,s);
        s.pop_back();
      }
  }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int> > r;
    r.push_back(vector<int>());
    vector<int> s;
    sort(nums.begin(), nums.end());
    subsetsWithDupHelper(nums, 0, r, s);
    return r;
}


// a solution without backtracking
//  add element one by one but skip the duplicates

vector<vector<int> > subsetsWithDup_linear(vector<int>& nums) {
  vector<vector<int> > r(1,vector<int>());
  int preSize = 1;
  sort(nums.begin(), nums.end());
  for(int i = 0; i < nums.size(); i++) {
    int curSize = r.size();
    if( 0 < i && nums[i] != nums[i-1] ) preSize = curSize;
    for(int j = curSize - preSize; j < curSize; j++) {
      r.push_back(r[j]);
      r.back().push_back(nums[i]);
    }
  }
  return r;
}
