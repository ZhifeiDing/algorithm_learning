#include "leetcode.hpp"
/*
 *
 *Given a list of unique words. Find all pairs of distinct indices (i, j)
 *in the given list, so that the concatenation of the two words, i.e.
 *words[i] + words[j] is a palindrome.
 *
 *Example 1:
 *Given words = ["bat", "tab", "cat"]
 *Return [[0, 1], [1, 0]]
 *The palindromes are ["battab", "tabbat"]
 *Example 2:
 *Given words = ["abcd", "dcba", "lls", "s", "sssll"]
 *Return [[0, 1], [1, 0], [3, 2], [2, 4]]
 *The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
 */
bool isPalindrome(string &s) {
    string revStr = s;
    reverse(revStr.begin(),revStr.end());
    return s == revStr;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_map<string, int> revWords;
    for(int i = 0; i < words.size(); ++i) {
        string revStr = words[i];
        reverse(revStr.begin(),revStr.end());
        revWords[revStr] = i;
    }

    set<vector<int> > r;
    for(int i = 0; i < words.size(); ++i) {
        for(int j = 0; j <= words[i].size(); ++j) {
            string prefix = words[i].substr(0,j);
            string postfix = words[i].substr(j);

            if( revWords.find(prefix) != revWords.end() && revWords[prefix] != i && isPalindrome(postfix) )
                r.insert(vector<int>{i, revWords[prefix]});

            if( revWords.find(postfix) != revWords.end() && revWords[postfix] != i && isPalindrome(prefix) )
                r.insert(vector<int>{revWords[postfix],i});
        }
    }
    vector<vector<int> > res;
    for(auto &itr : r)
        res.push_back(itr);
    return res;
}