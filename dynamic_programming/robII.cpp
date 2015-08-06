#include "leetcode.hpp"

/*
 * Note: This is an extension of House Robber.
 * 
 * After robbing those houses on that street, the thief has found himself a 
 * new place for his thievery so that he will not get too much attention. 
 * This time, all houses at this place are arranged in a circle. That means 
 * the first house is the neighbor of the last one. Meanwhile, the security 
 * system for these houses remain the same as for those in the previous 
 * street.
 * 
 * Given a list of non-negative integers representing the amount of money 
 * of each house, determine the maximum amount of money you can rob tonight 
 * without alerting the police.
 */
int robHelper(vector<int> & nums, int start, int end) {
    vector<int> r(end - start + 2, 0);
    r[1] = nums[start];
    for(int i = start + 2; i <= end+1; i++)
        r[i-start] = max(r[i-1-start], r[i-2-start] + nums[i-1]);
    return r[end-start+1];
}

int robII(vector<int>& nums) {
    if( nums.size() == 0 )
        return 0;
    if( nums.size() == 1 )
        return nums[0];
    return max(robHelper(nums, 0, nums.size()-2), robHelper(nums, 1, nums.size()-1));
}
