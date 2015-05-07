#include "leetcode.hpp"

void test_lengthOfLongestSubstring(void) {
  string s;
  srand((unsigned int)time(NULL));
  int n = rand() % 11;
  gen_string(s,n,true);
  cout << "Original String : ";
  print_string(s);
  cout << "Lenght of Longest Substring : " << lengthOfLongestSubstring(s) << endl;
  cout << "Lenght of Longest Substring : " << lengthOfLongestSubstring_map(s) << endl;
}
