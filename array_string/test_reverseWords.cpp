#include "leetcode.hpp"

void test_reverseWords(void) {
  srand((unsigned int)time(NULL));
  int n = rand() % 7;
  string s;
  int i = 0;
  while( i < n ) {
    string w;
    gen_string(w, rand() % 7 + 1, true);
    //print_string(w);
    s.append(w);
    s.append(string(i,' '));
    i++;
  }
  print_string(s);
  string r = reverseWords(s);
  print_string(r);
  r = reverseWords_2pass(s);
  print_string(r);

}

