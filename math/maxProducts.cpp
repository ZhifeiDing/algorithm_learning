#include "leetcode.hpp"

/*
 * Given a string array words, find the maximum value of 
 * length(word[i]) * length(word[j]) where the two words 
 * do not share common letters. You may assume that each 
 * word will contain only lower case letters. If no such 
 * two words exist, return 0.
 * 
 * Example 1:
 * Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 * Return 16
 * The two words can be "abcw", "xtfn".
 * 
 * Example 2:
 * Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 * Return 4
 * The two words can be "ab", "cd".
 * 
 * Example 3:
 * Given ["a", "aa", "aaa", "aaaa"]
 * Return 0
 * No such pair of words.
 */

/*
 * O(n^2) 
 */
int maxProducts(vector<string> &words) {
  vector<int> bit(words.size(),0);
  //vector<int> len(words.size(),0);

  int r = 0;

  for(int i = 0; i < words.size(); ++i) {
    for(auto itr : words[i]) {
      bit[i] |= 1 << ( itr - 'a' );
      //++len[i];
    }
    
    for(int j = 0; j < i; ++j) {
      if( ! (bit[j] && bit[i] ) )
        r = max(r, int(words[i].size() * words[j].size()));
    }
  }
  return r;
}
