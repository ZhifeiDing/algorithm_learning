#include "leetcode.hpp"
/*
 *
 *Write a function that takes a string as input and returns the string reversed.
 *
 *Example:
 *Given s = "hello", return "olleh".
 */

string reverseVowels(string s) {
    const unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    int left = 0, right = s.size()-1;
    while( left < right ) {
        while( left < right && vowels.find(s[left]) == vowels.end() )
            ++left;
        while( left < right && vowels.find(s[right]) == vowels.end() )
            --right;
        swap(s[left], s[right]);
    }
    return s;
}
