#include "leetcode.hpp"

/*
 * Given an integer array of size n, find all elements that appear 
 * more than ⌊ n/3 ⌋ times. The algorithm should run in linear time 
 * and in O(1) space.
 * 
 * Hint:
 * 
 * How many majority elements could it possibly have?
 */

vector<int> majorityElement(vector<int> & nums) {
  unordered_map<int,int> numCnt;
  const int k = 3;
  for(int i = 0; i < nums.size(); i++) {
    if( numCnt.find(nums[i]) == numCnt.end() ) {
      if( numCnt.size() == k ) {
        for(unordered_map<int,int>::iterator itr = numCnt.begin(); itr != numCnt.end();) 
          if( itr->second == 1 )
            itr = numCnt.erase(itr);
          else {
            itr->second--;
            itr++;
          }
      } 
      numCnt[nums[i]] = 1;
    } else
      numCnt[nums[i]]++;
  }
  vector<int> r;
  if( numCnt.size() == 0 ) return r;
  for(unordered_map<int,int>::iterator itr = numCnt.begin(); itr != numCnt.end(); ++itr)
    itr->second = 0;
  for(int i = 0; i < nums.size(); i++)
    if( numCnt.find(nums[i]) != numCnt.end() )
      numCnt[nums[i]]++;
  for(auto itr : numCnt)
    if( itr.second * k > nums.size() )
      r.push_back(itr.first);
  return r;
}
