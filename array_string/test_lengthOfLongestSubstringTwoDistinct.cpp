#include "leetcode.hpp"

void test_lengthOfLongestSubstringTwoDistinct(void) {
  string s;
  srand((unsigned int)time(NULL));
  int n = rand() % 9;
  gen_string(s,n,true);
  cout << "Original String : ";
  print_string(s);
  cout << "Length og Longest Two Distinct substring : " << lengthOfLongestSubstringTwoDistinct(s) << endl;
  cout << "Length og Longest Two Distinct substring : " << lengthOfLongestSubstringTwoDistinct_hash(s) << endl;
}
