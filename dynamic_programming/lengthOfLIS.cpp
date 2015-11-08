#include "leetcode.hpp"

/*
 * Given an unsorted array of integers, find the length of longest 
 * increasing subsequence.
 * 
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the 
 * length is 4. Note that there may be more than one LIS combination, 
 * it is only necessary for you to return the length.
 * 
 * Your algorithm should run in O(n2) complexity.
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 */

/*
 * dynamic programing
 * f[i] = max(f[i], f[j] + 1)
 */

int lengthOfLIS(vector<int> &nums) {
  if( nums.size() == 0 )
    return 0;
  int r = 1;
  vector<int> f(nums.size() + 1, 1);
  for(int i = 1; i < nums.size(); ++i) {
    for(int j = 0; j < i; ++j) {
      if( nums[i] > nums[j] )
        f[i] = max(f[i], f[j] + 1);
    }
    f[nums.size()] = max(f[nums.size()], f[i]);
  }
  return f.back();
}

/*
 * lower_bound
 */
int lengthOfLIS_lowerbound(vector<int> &nums) {
  if( nums.size() == 0 )
    return 0;
  vector<int> r(1,nums[0]);
  for(int i = 1; i < nums.size(); ++i) {
    if( r.back() <= nums[i] )
      r.push_back(nums[i]);
    else {
      auto itr = lower_bound(r.begin(), r.end(), nums[i]);
      *itr = nums[i];
    }
  }
  return r.size();
}

/*
 * binary search
 *
 */
int binarySearch(vector<int> &nums, int l, int r, int val) {
  while( l < r ) {
    int m = l + ( r - l ) / 2;
    if( nums[m] < val )
      l = m + 1;
    else if( val < nums[m] )
      r = m;
    else
      return m;
  }
  return l;
}

int lengthOfLIS_bs(vector<int> &nums) {
  if( nums.size() == 0 )
    return 0;
  vector<int> r(1, nums[0]);
  for(int i = 1; i < nums.size(); ++i) {
    if( r.back() <= nums[i] )
      r.push_back(nums[i]);
    else 
      r[binarySearch(r, 0, r.size()-1, nums[i])] = nums[i];
  }
  return r.size();
}
