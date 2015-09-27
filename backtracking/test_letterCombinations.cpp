#include "leetcode.hpp"

void test_letterCombinations() {
  srand((unsigned int)time(NULL));
  int n =rand()%1000;
  vector<string> r = letterCombinations(to_string(n));
  cout << n << " mapped to letters : " << endl;
  for(int i = 0; i < r.size(); ++i)
    cout << i << " : " << r[i] << endl;
}
