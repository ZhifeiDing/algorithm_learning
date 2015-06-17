#include "leetcode.hpp"

/*
 * You are a professional robber planning to rob houses along a street. 
 * Each house has a certain amount of money stashed, the only constraint 
 * stopping you from robbing each of them is that adjacent houses have 
 * security system connected and it will automatically contact the police 
 * if two adjacent houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money 
 * of each house, determine the maximum amount of money you can rob 
 * tonight without alerting the police.
 */

int rob(vector<int>& nums) {
    vector<int> f(nums.size()+1,0);
    if( nums.size() == 0 ) return 0;
    f[1] = nums[0];
    for(int i = 2; i <= nums.size(); i++) {
        f[i] = max(f[i-1], f[i-2] + nums[i-1]);
    }
    return f[nums.size()];
}
