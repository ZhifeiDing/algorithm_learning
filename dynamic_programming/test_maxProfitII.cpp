#include "leetcode.hpp"

void test_maxProfitVI(void) {
  srand((unsigned int)time(NULL));
  int n = rand()%15;
  int k = rand()%10;
  vector<int> prices;
  gen_array(n, prices);
  print_array(prices);

  cout << "k = " << k << ", Max Profit : " << maxProfitVI(k, prices) << endl;
}
