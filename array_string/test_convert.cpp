#include "leetcode.hpp"

void test_convert() {
  srand((unsigned int)time(NULL));
  string s;
  int numRows = rand()%12 + 1;
  int n = rand()%20;
  gen_string(s,n);
  cout << s << endl;
  string r = convert(s, numRows);
  cout << r << endl;
}
