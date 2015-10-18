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
// O(n)
//using Tortoise & Hair algorithm by Donald Knuth to find cycle in a sequence.
//This algorithm also called Floyd's cycele detection algorithm
//
int findDuplicate(vector<int> & nums) {
  int fast = nums.size();
  int slow = nums.size();

  do {
    slow = nums[slow-1];
    fast = nums[nums[fast-1]-1];
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

// count the number of bit 1 from 1 to n
int findDuplicate_bit(vector<int> & nums) {
  vector<int> cntCompleteBit(32,0);
  for(int i = 1; i < nums.size(); ++i) {
    for(int j = 0; j < cntCompleteBit.size(); ++j)
      cntCompleteBit[j] += ( i & ( 1 << j ) );
  }
  vector<int> cntBit(32,0);
  for(int i = 0; i < nums.size(); ++i) {
    for(int j = 0; j < cntBit.size(); ++j)
      cntBit[j] += ( nums[i] & ( 1 << j ) );
  }
  int r = 0;
  for(int i = 0; i < cntBit.size(); ++i)
    r += cntCompleteBit[i] < cntBit[i] ? 1 << i : 0;
  return r;
}
