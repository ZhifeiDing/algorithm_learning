/*
 * Question:  
 * Similar to Question [6. Reverse Words in a String], but with the 
 * following constraints: “The input string does not contain leading 
 * or trailing spaces and the words are always separated by a single space.”  
 * Could you do it in-place without allocating extra space? 
 */
#include "leetcode.hpp"
/*
 * Solution:  
 * O(n) runtime, O(1) space – In-place reverse:  Let us indicate the ith 
 * word by wi and its reversal as wi′. Notice that when you reverse a word 
 * twice, you get back the original word. That is, (wi′)′ = wi.  The input 
 * string is w1 w2 … wn. If we reverse the entire string, it becomes wn′ … w2′ w1′. 
 * Finally, we reverse each individual word and it becomes wn … w2 w1. 
 * Similarly, the same result could be reached by reversing each individual word 
 * first, and then reverse the entire string.
 */
void reverseAWord(char s[], int n) {
  int i = 0, j = n -1;
  while( i < j ) {
    swap(s[i],s[j]);
    i++;
    j--;
  }
}
void reverseWordsII(char s[],int n) {
  int start = 0;
  for(int i = 0; i < n; i++) {
    if( s[i] == ' ' ) {
      reverseAWord(&s[start], i - start);
      start = i + 1;
    } else if( i == n - 1 ) {
      reverseAWord(&s[start], i - start + 1);
    }
  }
  reverseAWord(s,n);
}

