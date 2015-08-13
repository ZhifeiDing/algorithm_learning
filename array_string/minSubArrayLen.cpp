#include "leetcode.hpp"

/*
 * Given an array of n positive integers and a positive integer s, 
 * find the minimal length of a subarray of which the sum ≥ s. If 
 * there isn't one, return 0 instead.
 * 
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 * 
 * click to show more practice.
 * 
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution 
 * of which the time complexity is O(n log n).
 */
int minSubArrayLen(int s, vector<int> & nums) {
  int right = 0, left = 0;
  int len = nums.size()+1;
  int sum = 0;
  while( right < nums.size() ) {
    while( sum < s && right < nums.size() )
      sum += nums[right++];
    while( s <= sum ) {
      len = min(len, right - left);
      sum -= nums[left++];
    }
  }
  return len == nums.size() + 1 ? 0 : len;
}
