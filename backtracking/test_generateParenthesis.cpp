#include "leetcode.hpp"

void test_generateParenthesis() {
  srand((unsigned int)time(NULL));
  int n = rand()%7;
  vector<string> r = generateParenthesis(n);
  cout << " n = " << n << endl;
  for(int i = 0; i < r.size(); ++i)
    cout << i << " : " << r[i] << endl;
}
