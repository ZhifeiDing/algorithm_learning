#include "leetcode.hpp"
/*
 * Given an array nums containing n + 1 integers where each 
 * integer is between 1 and n (inclusive), prove that at least 
 * one duplicate number must exist. Assume that there is only 
 * one duplicate number, find the duplicate one.
 * 
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could 
 * be repeated more than once.
 */

// use the index as pointers to find the intersection point
int findDuplicate(vector<int> & nums) {
  int fast = nums.size();
  int slow = nums.size();

  do {
    slow = nums[slow-1];
    fast = nums[fast-1];
  } while( slow != fast );
  slow = nums.size();
  while( slow != fast ) {
    slow = nums[slow-1];
    fast = nums[fast-1];
  }
  return slow;
}

// binary search O(logn)
int cntRanges(vector<int> & nums, int l, int r) {
  int cnt = 0;
  for(auto i : nums ) {
    if( i <= r && l <= i )
      ++cnt;
  }
  return cnt;
}
int findDuplicate_bs(vector<int> & nums) {
  int l = 1, r = nums.size();
  while( l < r ) {
    int m = l + ( r - l ) / 2;
    int cnt = cntRanges(nums, l, m);
    if( cnt > m -l + 1 )
      r = m;
    else
      l = m + 1;
  }
  return l;
}