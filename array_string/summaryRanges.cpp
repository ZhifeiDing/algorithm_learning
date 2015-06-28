#include "leetcode.hpp"

/*
 * Given a sorted integer array without duplicates, return the 
 * summary of its ranges.
 * 
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

string formString(int start, int end) {
    stringstream ss;
    ss << start;
    if( start == end )
        return ss.str();
    ss << "->";
    ss << end;
    return ss.str();
}
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> r;
    if( nums.size() == 0 ) return r;
    nums.push_back(nums.back());
    int start = 0;
    for(int i = 1; i < nums.size(); i++) {
        if( nums[i] - nums[i-1] != 1 ) {
            r.push_back(formString(nums[start],nums[i-1]));
            start = i;
        }
    }
    return r;
}
