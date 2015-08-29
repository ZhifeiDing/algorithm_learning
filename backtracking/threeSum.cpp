#include "leetcode.hpp"
/*
 * Given an array S of n integers, are there elements a, b, c 
 * in S such that a + b + c = 0? Find all unique triplets in 
 * the array which gives the sum of zero.
 * 
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *     For example, given array S = {-1 0 1 2 -1 -4},
 * 
 *     A solution set is:
 *     (-1, 0, 1)
 *     (-1, -1, 2)
 */

void threeSumHelper(vector<int> & nums, vector<vector<int> > &r, vector<int> &s, int sum, int start, bool & get) {
    for(int i = start; i < nums.size(); i++) {
        if( start == 0 && nums[i] >= 0 ) {
            return;
        }
        if( start == 0 && i > nums.size() - 3 )
          return;
        if( s.size() == 3 ) {
            if( sum == 0 ) {
                r.push_back(s);
                get = true;
            }
            return;
        }
        //if( nums[i] >= 0 && sum > 0 )
        s.push_back(nums[i]);
        threeSumHelper(nums, r, s, sum + nums[i], i + 1, get);
        s.pop_back();
        if( get ) {
            if( s.size() == 1 ) {
                get = false;
                int j = i + 1;
                while( nums[j] == nums[i] ) 
                  j++;
                i = j;
            } else
                return;
        }
    }
}
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > r;
    vector<int> s;
    if( nums.size() < 3 ) return r;
    sort(nums.begin(), nums.end());
    bool get = false;
    threeSumHelper(nums, r, s, 0, 0, get);
    return r;
}
