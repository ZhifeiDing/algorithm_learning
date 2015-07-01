#include "leetcode.hpp"

/*
 * Given an array of strings, return all groups of strings that 
 * are anagrams.
 * 
 * Note: All inputs will be in lower-case.
 */

vector<string> anagrams(vector<string>& strs) {
    unordered_map<string, int> strMap;
    vector<string> r;
    for(int i = 0; i < strs.size(); i++) {
        string s = strs[i];
        sort(s.begin(), s.end());
        if( strMap.find(s) == strMap.end() ) {
            strMap[s] = i;
        } else {
            if( strMap[s] >= 0 ) {
                r.push_back(strs[strMap[s]]);
                strMap[s] = -1;
            }
            r.push_back(strs[i]);
        }
    }
    return r;
}
