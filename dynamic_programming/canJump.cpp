#include "leetcode.hpp"

/*
 * Given an array of non-negative integers, you are initially 
 * positioned at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length 
 * at that position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * For example:
 * A = [2,3,1,1,4], return true.
 * 
 * A = [3,2,1,0,4], return false.
 */
bool canJump(vector<int>& nums) {
    if( nums.size() < 2 ) return true;
    if( nums[0] == 0 ) return false;
    
    int pos = nums.size() - 1;
    int i = nums.size() - 2;
    while( i >= 0 ) {
        pos = ( nums[i] + i > pos - 1 ) ? i : pos;
        i--;
    }
    return pos == 0;
}
bool canJump_start(vector<int>& nums) {
    if( nums.size() < 2 ) return true;
    if( nums[0] == 0 ) return false;
    
    int maxpos = 0;
    for(int i = 0; i < nums.size() && maxpos < nums.size() - 1; i++) {
        if( i > maxpos ) return false;
        maxpos = ( nums[i] + i > maxpos ) ? nums[i] + i : maxpos;
    }
    return true;
}
