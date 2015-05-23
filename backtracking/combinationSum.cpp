#include "leetcode.hpp"
/*
 * Given a set of candidate numbers (C) and a target number (T), 
 * find all unique combinations in C where the candidate numbers sums to T.
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending
 * order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 */

void combinationSumHelper(vector<int> & candidates, int target, vector<vector<int> > & r, vector<int> & one, int start) {
    for(int i = start; i < candidates.size(); i++) {
        if( target == candidates[i] ) {
            one.push_back(candidates[i]);
            r.push_back(one);
            one.pop_back();
        } else if( target > candidates[i] ) {
            one.push_back(candidates[i]);
            combinationSumHelper(candidates, target - candidates[i], r, one, i);
            one.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> > r;
    vector<int> one;
    sort(candidates.begin(), candidates.end());
    combinationSumHelper(candidates, target, r, one, 0);
    return r;
}
