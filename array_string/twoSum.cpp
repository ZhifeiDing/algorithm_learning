/*
 * Question:  
 *    Given an array of integers, find two numbers such that 
 * they add up to a specific target number.  The function twoSum should 
 * return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2. Please note that your returned 
 * answers (both index1 and index2) are not zero-based.  You may assume 
 * that each input would have exactly one solution.
 */
#include "leetcode.hpp"

// brute force 
vector<int> twoSum(vector<int> & numbers, int target) {
  for(int i = 0; i < numbers.size() - 1; i++)
    for(int j = i + 1; j < numbers.size(); j++)
      if( numbers[i] + numbers[j] == target ) {
        return vector<int>{i+1,j+1};
      }
  return vector<int>(2,-1);
}

// hash 
vector<int> twoSum_hash(vector<int> & numbers, int target) {
  unordered_map<int, int> m;
  for(int i = 0; i < numbers.size(); i++) {
    if( m.find(target - numbers[i]) != m.end() )
      return vector<int> {m[target-numbers[i]],i+1};
    m[numbers[i]] = i + 1;
  }
  return vector<int> {-1,-1};
}
