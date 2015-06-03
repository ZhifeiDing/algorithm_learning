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

void reverseAWord(string & s, int l, int r) {
    while( l < r ) {
        swap(s[l], s[r]);
        l++;
        r--;
    }
}


string reverseWords_2pass(const string & r) {
   string s = r;
    // reduce leadig and trailing sapces
    int i = 0;
    while( i < s.size() && s[i] == ' ' ) 
        i++;
    int j = s.size()-1;
    while( i < j && s[j] == ' ' )
        j--;
    if( i > j ) {  
        s = s.substr(0,0); 
        return s; 
    }
    s = s.substr(i,j-i+1);
    
    i = 0;
    j = i;
    while( i < s.size() ) {
        if( s[i] == ' ' || i == s.size()-1 ) {
            while( j > 0 && s[j] == ' ' )
                j--;
            if( j == 0 ) 
              reverseAWord(s, j, i-1);
            else
              reverseAWord(s, j+1, i);
            j = i;
            while( i < s.size() - 2 && s[i] == ' ' )
                i++;
        }
        i++;
    }
    
    // reduce all the spaces at the end
    i = s.size()-1;
    while( i > 0 && s[i] == ' ' )
        i--;
    s = s.substr(0, i+1);
    
    reverseAWord(s, 0, s.size()-1);
    return s;    
}
