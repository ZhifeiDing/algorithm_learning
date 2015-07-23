#include "leetcode.hpp"

/*
 * Given an array of integers, find out whether there are two distinct 
 * indices i and j in the array such that the difference between nums[i] 
 * and nums[j] is at most t and the difference between i and j is at 
 * most k.
 */
bool cmpptr(int *a, int *b) {
    return *a < *b;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
          vector<int*> numptr(nums.size());
          for(int i = 0; i < nums.size(); i++)
              numptr[i] = &nums[i];
          sort(numptr.begin(), numptr.end(), cmpptr);
          for(int i = 0; i < nums.size(); i++) {
              for(int j = i+1; j < nums.size(); j++) {
                    if( *numptr[j] > *numptr[i] + t )
                        break;
                    if( abs(numptr[j] - numptr[i]) <= k )
                        return true;
              }
          }
          return false;
}
