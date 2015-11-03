#include "leetcode.hpp"

/*
 * Given an array S of n integers, are there elements 
 * a, b, c, and d in S such that a + b + c + d = target? 
 * Find all unique quadruplets in the array which gives 
 * the sum of target.
 * 
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending 
 * order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 *     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * 
 *     A solution set is:
 *     (-1,  0, 0, 1)
 *     (-2, -1, 1, 2)
 *     (-2,  0, 0, 2)
 */

int binarySearch(vector<int> & nums, int l, int r, int t) {
  while( l < r ) {
    int last = l + ( r - l ) / 2;
    if( t < 

vector<vector<int> > fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > r;
    unodered_map<int, int> numsCnt;
    for(auto i : nums)
      ++numsCnt[i];

    int l = 0, r = nums.size() - 1;

    while( l + 2 < r ) {
      int mid = l + ( r - l ) / 2;
      int t = target - ( nums[l] + nums[r] + nums[mid] );
      if( t < nums[l] ) {
        --r;
        continue;
      }
      if( nums[r] < t ) {
        ++l;
        continue;
      }
      // if nums[mid] == t we can search in the hash table
      int last = binarySearch(nums, l, r, t);
      if( last != -1 ) {
        if( last < mid )
          r.push_back(vector<int>{nums[l], nums[last], nums[mid], nums[r]});
        else if( mid < last )
          r.push_back(vector<int>{nums[l], nums[mid], nums[last], nums[r]});

        if( numsCnt[nums[last]] > 1 ) {
          for(int i = 0; i < numsCnt[t] - 1; ++i) {
            if( mid == last )
              r.push_back(vector<int>{nums[l], nums[mid], nums[mid],nums[r]});
            else
              r.push_back(r.back());
          }
        }
      }
      ++l;
      --r;
    }
    return r;
}
