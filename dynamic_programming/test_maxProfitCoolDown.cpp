#include "leetcode.hpp"

void test_maxProfitCoolDown() {
  srand((unsigned int)time(NULL));
  int n = rand()%15;
  vector<int> prices;
  gen_array(n, prices);
  print_array(prices);

  cout << "Max Profit : " << maxProfitCoolDown(prices) << endl;
  cout << "Max Profit : " << maxProfitCoolDown_novector(prices) << endl;
}
