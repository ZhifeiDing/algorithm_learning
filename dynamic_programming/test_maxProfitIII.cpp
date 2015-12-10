#include "leetcode.hpp"

void test_maxProfitIII(void) {
  srand((unsigned int)time(NULL));
  int n = rand()%15;
  vector<int> prices;
  gen_array(n, prices);
  print_array(prices);

  cout << "Max Profit : " << maxProfitIII(prices) << endl;
}
