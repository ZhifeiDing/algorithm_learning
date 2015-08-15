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
/*
 * two pointer : O(n) 
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

/*
 * binary search : O(nlogn)
 * keypoint : maintain a non-decreasing array
 */
void accumulate(vector<int> & nums, vector<int> sum) {
  for(int i = 0; i < nums.size(); i++)
    sum[i] = sum[i-1] + nums[i];
}

int upper_bound(vector<int> & nums, int left, int right, int target) {
  while( left < right ) {
    int mid = left + ( right - left ) / 2;
    if( nums[mid] > target )
      right = mid;
    else
      left = mid + 1;
  }
  if( nums[right] > target )
    return right;
  if( nums[left] > target )
    return left;
  return -1;
}
int minSubArrayLen_BS(int s, vector<int> & nums) {
  vector<int> sum(nums.size());
  if( nums.size() == 0 )
    return 0;
  sum[0] = nums[0];
  accumulate(nums,sum);
  int len = nums.size() + 1;
  for(int i = 0; i < nums.size(); i++) {
    int j = upper_bound(sum, 0, i, sum[i] - s);
    len = j == -1 ? len : min(len, i - j + 1);
  }
  return len == nums.size() + 1 ? 0 : len;
}
