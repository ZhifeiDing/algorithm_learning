/*
 * Question:  Given a string S, find the longest palindromic 
 * substring in S. You may assume that the maximum length of 
 * S is 1000, and there exists one unique longest palindromic 
 * substring. 
 * Hint:  First, make sure you understand what a palindrome means. 
 * A palindrome is a string  which reads the same in both directions. 
 * For example, “aba” is a palindome, “abc” is not. 
 */
/*
 * A common mistake:  Some people will be tempted to come up with 
 * a quick solution, which is unfortunately flawed (however can 
 * be corrected easily):  Reverse S and become S’. 
 * Find the longest common substring between S and S’, which must 
 * also be the longest palindromic substring. This seemed to work, 
 * let’s see some examples below. For example, S = “caba”, S’ = “abac”.  
 * The longest common substring between S and S’ is “aba”, which is 
 * the answer. Let’s try another example: S = “abacdfgdcaba”, 
 * S’ = “abacdgfdcaba”.  The longest common substring between S and S’ 
 * is “abacd”. Clearly, this is not a valid palindrome.  We could see 
 * that the longest common substring method fails when there exists a 
 * reversed copy of a non-palindromic substring in some other part of 
 * S. To rectify this, each time we find a longest common substring 
 * candidate, we check if the substring’s indices are the same as the 
 * reversed substring’s original indices. If it is, then we attempt to 
 * update the longest palindrome found so far; if not, we skip this and 
 * find the next candidate.  This gives us an O(n2) DP solution which 
 * uses O(n2) space (could be improved to use O(n) space). Please read 
 * more about Longest Common Substring here. 
 */ 
/*
 * O(n3) runtime, O(1) space – Brute force:  The obvious brute force 
 * solution is to pick all possible starting and ending positions for 
 * a substring, and verify if it is a palindrome. There are a total of       
 * such substrings (excluding the trivial solution where a character itself 
 * is a palindrome). Since verifying each substring takes O(n) time, 
 * the run time complexity is O(n3).    
 * 
 * O(n2) runtime, O(n) space – Dynamic programming:  To improve over the 
 * brute force solution from a DP approach, first think how we can avoid 
 * unnecessary re-computation in validating palindromes. Consider the case 
 * “ababa”. If we already knew that “bab” is a palindrome, it is obvious 
 * that “ababa” must be a palindrome since the two left and right end letters 
 * are the same. Stated more formally below:  Define P[ i, j ] ← true iff the 
 * substring Si … Sj is a palindrome, otherwise false. Therefore,  P[ i, j ] ← 
 * ( P[ i+1, j-1 ] and Si = Sj ) The base cases are: P[ i, i ] ← true  
 * P[ i, i+1 ] ← ( Si = Si+1 )  This yields a straight forward DP solution, 
 * which we first initialize the one and two letters palindromes, and work 
 * our way up finding all three letters palindromes, and so on…   This gives 
 * us a runtime complexity of O(n2) and uses O(n2) space to store the table. 
 * Additional exercise:  Could you improve the above space complexity further 
 * and how?
 */
/*
 * O(n2) runtime, O(1) space – Simpler solution:  In fact, we could solve 
 * it in O(n2) time using only constant space.  We observe that a palindrome 
 * mirrors around its center. Therefore, a palindrome can be expanded from its 
 * center, and there are only 2n – 1 such centers.  You might be asking why 
 * there are 2n – 1 but not n centers? The reason is the center of a palindrome 
 * can be in between two letters. Such palindromes have even number of letters 
 * (such as “abba”) and its center are between the two ‘b’s.  Since expanding a 
 * palindrome around its center could take O(n) time, the overall complexity is 
 * O(n2).
 */
#include "leetcode.hpp"
int expandAroundCenter(string & s, int left, int right) {
  int L = left, R = right;
  while(L>=0 && R< s.size() && s[L] == s[R]) {
    L--;
    R++;
  }
  return R-L-1;
}
string longestPalindrome(string & s) {
  int start = 0, end = 0;
  for(int i = 0; i < s.size(); i++) {
    int len1 = expandAroundCenter(s,i,i);
    int len2 = expandAroundCenter(s,i,i+1);
    len1 = max(len1,len2);
    if( len1 > end -start + 1 ) {
      start = i - (len1 -1)/2;
      end = i + len1/2;
    }
  }
  return s.substr(start,end + 1);
}


