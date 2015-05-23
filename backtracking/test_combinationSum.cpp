#include "leetcode.hpp"

void test_combinationSum(void) {
  srand((unsigned int)time(NULL));
  int n = rand()%5 + 1;
  vector<int> candidates;
  gen_array(n,candidates,7);
  print_array(candidates);
  vector<vector<int> > r = combinationSum(candidates, n);
  for(int i = 0; i < r.size(); i++) {
    for(int j = 0; j < r[i].size(); j++)
      cout << r[i][j] << " ";
    cout << endl;
  }
}



