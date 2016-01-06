#include "leetcode.hpp"

void test_numTrees() {
  srand((unsigned int)time(NULL));
  int n = rand()%50;
  cout << n << " have " << numTrees(n) << " trees" << endl;
}
