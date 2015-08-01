#include "leetcode.hpp"

/*
 * Given two strings s and t, write a function to determine if t is an 
 * anagram of s.
 * 
 * For example,
 *     s = "anagram", t = "nagaram", return true.
 *     s = "rat", t = "car", return false.
 * 
 *     Note:
 *     You may assume the string contains only lowercase alphabets.
 */
bool isAnagram(string s, string t) {
    unordered_map<char, int> charCnt;
    if( s.size() != t.size() )
        return false;
    for(int i = 0; i < s.size(); i++) {
        charCnt[s[i]]++;
    }
    for(int i = 0; i < s.size(); i++)
        if( charCnt.find(t[i]) == charCnt.end() || charCnt[t[i]] == 0 )
            return false;
        else
            charCnt[t[i]]--;
    return true;
}
