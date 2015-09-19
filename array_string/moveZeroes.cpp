#include "leetcode.hpp"

/*
 * Given an array nums, write a function to move all 0's to the end of it 
 * while maintaining the relative order of the non-zero elements.
 * 
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, 
 * nums should be [1, 3, 12, 0, 0].
 * 
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */

void moveZeroes(vector<int>& nums) {
    int zero = 0, idx = 0;
    while( zero < nums.size() && nums[zero] != 0) {
        ++zero;
    }
    idx = zero + 1;
    while( idx < nums.size() ) {
        if( nums[idx++] != 0 )
            swap(nums[zero++], nums[idx-1]);
    }
}
