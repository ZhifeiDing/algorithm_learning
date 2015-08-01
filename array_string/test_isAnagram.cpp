#include "leetcode.hpp"

void test_isAnagram() {
  string s, t;
  srand((unsigned int)time(NULL));
  int n = rand()%13;
  gen_string(s,n,true);
  gen_string(t,n,true);
  cout << "s = " << s << endl << "t = " << t << endl;
  string r = isAnagram(s,t) ? " s and t is anagram " : " s and t is not anagram ";
  cout << r << endl;
}
