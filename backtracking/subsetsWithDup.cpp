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
