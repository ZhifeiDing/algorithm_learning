#include "leetcode.hpp"
/*
 *
 *Given an unsorted array return whether an increasing subsequence of
 *length 3 exists or not in the array.
 *
 *Formally the function should:
 *Return true if there exists i, j, k
 *such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
 *Your algorithm should run in O(n) time complexity and O(1) space complexity.
 *
 *Examples:
 *Given [1, 2, 3, 4, 5],
 *return true.
 *
 *Given [5, 4, 3, 2, 1],
 *return false.
 */
bool increasingTriplet(vector<int>& nums) {
        vector<int> s;
        int k = 3;
        if( nums.size() < k )
            return false;
        for(int i = 0; i < nums.size() && s.size() < k; ++i) {
            if( !s.empty() && s.back() >= nums[i] )
                *(lower_bound(s.begin(), s.end(), nums[i])) = nums[i];
            else
                s.push_back(nums[i]);
        }
        return s.size() == k;
}
