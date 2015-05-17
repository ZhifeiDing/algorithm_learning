#include "leetcode.hpp"
/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    int i = 0;
    while( i < n ) { 
        if( nums[i] == val ) {
            swap(nums[i], nums[n-1]);
            n--;
        } else {
            i++;
        }
    }
    return n;
}
