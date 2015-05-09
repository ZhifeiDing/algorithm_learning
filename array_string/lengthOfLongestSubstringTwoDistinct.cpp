/*
 * Question:  Given a string S, find the length of the longest 
 * substring T that contains at most two distinct characters. 
 * For example, Given S = “eceba”,  T is "ece" which its length 
 * is 3. 
 */
#include "leetcode.hpp"
/*
 * Solution:  First, we could simplify the problem by assuming 
 * that S contains two or more distinct characters, which means 
 * T must contain exactly two distinct characters.  The brute 
 * force approach is O(n3) where n is the length of S. We can form 
 * every possible substring, and for each substring insert all 
 * characters into a Set which the Set’s size indicating the number 
 * of distinct characters. This could be easily improved to O(n2) by 
 * reusing the same Set when adding a character to form a new substring.  
 * The trick is to maintain a sliding window that always satisfies the 
 * invariant where there are always at most two distinct characters in 
 * it. When we add a new character that breaks this invariant, how can 
 * we move the begin pointer to satisfy the invariant? Using the above 
 * example, our first window is the substring “abba”. When we add the 
 * character ‘c’ into the sliding window, it breaks the invariant. 
 * Therefore, we have to readjust the  window to satisfy the invariant 
 * again. The question is which starting point to choose so the invariant 
 * is satisfied.  Let’s look at another example where S = “abaac”. We 
 * found our first window “abaa”. When we add ‘c’ to the window, the next 
 * sliding window should be “aac”.  This method iterates n times and therefore 
 * its runtime complexity is O(n). We use three pointers: i, j, and k. 
 */
int lengthOfLongestSubstringTwoDistinct(string s) {
  int i = 0, j = -1, maxLen = 0;
  for(int k = 1; k < s.size(); k++) {
    if( s[k] == s[k-1] ) continue;
    if( j >= 0 && s[j] != s[k] ) {
      maxLen = max(maxLen, k - i);
      i = j + 1;
    }
    j = k - 1;
  }
  return max((int)s.size()-i,maxLen);
}

int lengthOfLongestSubstringTwoDistinct_hash(string s) {
 bitset<256> count;
 int k = 2,j=0;
 int maxLen = 0, distinctCnt = 0;
 for(int i = 0; i < s.size(); i++) {
   if( count[s[i]] == 0 ) distinctCnt++;
   count[s[i]] = count[s[i]] + 1;
   while( distinctCnt > k ) {
     count[s[j]] = count[s[j]] - 1;
     if( count[s[j]] == 0 ) distinctCnt--;
     j++;
   }
   maxLen = max(i-j+1,maxLen);
 }
 return maxLen;
}


