#include "leetcode.hpp"

void test_bulbSwitch() {
  srand((unsigned int)1);
  int n = rand()%200;
  cout << n << " round , " << bulbSwitch(n) << " bulbs remain on\n";
}
