#include "leetcode.hpp"
/*
 * Given a string containing just the characters '(', ')', 
 * '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and 
 * "()[]{}" are all valid but "(]" and "([)]" are not.
 */

unordered_map<char,char> charMap = { {'(',')'}, {'{','}'}, {'[',']'} };
bool isValid(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        if( !st.empty() && charMap[st.top()] == s[i] )
            st.pop();
        else
            st.push(s[i]);
    }
    return st.empty();
}
