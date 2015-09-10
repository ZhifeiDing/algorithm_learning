#include "leetcode.hpp"

/*
 * Given an array S of n integers, find three integers in S such that 
 * the sum is closest to a given number, target. Return the sum of 
 * the three integers. You may assume that each input would have 
 * exactly one solution.
 * 
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

int threeSumClosest(vector<int> & nums, int target) {
  sort(nums.begin(), nums.end());
  int diff, min_diff = INT_MAX;
  for(int i = 0; i < nums.size(); i++) {
    int j = i + 1, k = nums.size()-1;
    while( j < k ) {
      diff = nums[i] + nums[j] + nums[k] - target;
      if( diff == 0 )
        return target;
      if( abs(diff) < abs(min_diff) )
        min_diff = diff;
      if( diff < 0 )
        ++j;
      else
        --k;
    }
  }
  return target + min_diff;
}
