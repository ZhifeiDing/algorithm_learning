#include "leetcode.hpp"
/*
 * Given an array of integers, find if the array contains any duplicates. 
 * Your function should return true if any value appears at least twice in 
 * the array, and it should return false if every element is distinct.
 */
bool containsDuplicate(vector<int> & nums) {
  unordered_set<int> numCnt;
  for(int i = 0; i < nums.size(); i++) {
    if( numCnt.find(nums[i]) != numCnt.end() )
      return true;
    numCnt.insert(nums[i]);
  }
  return false;
}
