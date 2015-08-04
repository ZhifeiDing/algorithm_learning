#include "leetcode.hpp"

void test_combinationSum3() {
  srand((unsigned int)time(NULL));
  int n = rand()%55 + 1;
  int t = n > 10 ? 10 : n;
  int k = rand()%t;
  vector<vector<int> > r = combinationSum3(k, n);
  cout << "k = " << k << ", n = " << n << endl;
  for(int i = 0; i < r.size(); i++) {
    cout << "[";
    for(int j = 0; j < r[0].size(); j++) {
      cout << r[i][j];
      if( j != r[0].size() - 1 )
        cout << ",";
    }
    cout << "]";
    if( i != r.size() - 1 )
      cout << ",";
  }
  cout << endl;
}
