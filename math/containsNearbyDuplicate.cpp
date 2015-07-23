#include "leetcode.hpp"
/*
 * Given an array of integers and an integer k, find out whether there 
 * there are two distinct indices i and j in the array such that 
 * nums[i] = nums[j] and the difference between i and j is at most k.
 */
bool containsNearbyDuplicate(vector<int> & nums, int k) {
  unordered_map<int,int> numCnt;
  for(int i = 0; i < nums.size(); i++) {
    if( numCnt.find(nums[i]) != numCnt.end() && i - numCnt[nums[i]] <= k )
      return true;
    numCnt[nums[i]] = i;
  }
  return false;
}
