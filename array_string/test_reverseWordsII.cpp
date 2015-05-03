#include "leetcode.hpp"

void test_reverseWordsII(void) {
  srand((unsigned int)time(NULL));
  int n = rand() % 7;
  string s;
  int i = 0;
  while( i < n ) {
    string w;
    gen_string(w, rand() % 7 + 1, true);
    //print_string(w);
    s.append(w);
    if( i != n - 1 ) 
      s.append(string(1,' '));
    i++;
  }
  char c[s.size() + 1];
  s.copy(c,s.size(),0);
  c[s.size()+1] = '\0';
  print_string(s);
  reverseWordsII(c, s.size());
  string r((const char*)c, s.size());
  print_string(r);
}
