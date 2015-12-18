#include "leetcode.hpp"

void test_removeDuplicateLetters() {
  srand((unsigned int)time(NULL));
  int n = rand()%20;
  string s;
  gen_string(s,n,true);
  cout << " s = " << s << endl;
  string r = removeDuplicateLetters(s);
  cout << " r = " << r << endl;
}
