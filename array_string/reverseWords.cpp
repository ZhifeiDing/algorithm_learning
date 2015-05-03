/*
 * Question:  Given an input string s, reverse the string word by word. 
 * For example, given s = "the sky is blue", return "blue is sky the".  
 * Example Questions Candidate Might Ask:  
 */
/*
 * Q: What constitutes a word?  
 * A: A sequence of non-space characters constitutes a word.  
 * Q: Does tab or newline character count as space characters?  
 * A: Assume the input does not contain any tabs or newline characters.  
 * Q: Could the input string contain leading or trailing spaces?  
 * A: Yes. However, your reversed string should not contain leading or 
 * trailing spaces. 
 * Q: How about multiple spaces between two words? 
 * A: Reduce them to a single space in the reversed string.  
 */
#include "leetcode.hpp"
/*
 * Solution:  O(n) runtime, O(n) space:  One simple approach is a two-pass 
 * solution: First pass to split the string by spaces into an array of words, 
 * then second pass to extract the words in reversed order.  We can do 
 * better in one-pass. While iterating the string in reverse order, we keep 
 * track of a word’s begin and end position. When we are at the beginning of 
 * a word, we append it.
 */
string reverseWords(const string & s) {
  string r;
  int start = s.size();
  for(int i = s.size()-1; i >= 0; i--) {
    if( s.c_str()[i] == ' ' ) {
      if( i != start - 1)
        r.append(s, i + 1, start - i);
      start = i;
    } else if( i == 0 ) {
      r.append(s, i, start - i);
    }
  }
  return r;
}

