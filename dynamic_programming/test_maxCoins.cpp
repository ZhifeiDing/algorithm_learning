#include "leetcode.hpp"

void test_maxCoins() {

  srand((unsigned int)time(NULL));
  int n = rand()%15;
  vector<int> nums;
  gen_array(n, nums);
  print_array(nums);

  cout << "Max Coins of Burst Ballons = " << maxCoins(nums) << endl;
  cout << "Max Coins of Burst Ballons = " << maxCoins_dc(nums) << endl;
}
