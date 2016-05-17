#include "leetcode.hpp"

void test_countBits() {
  srand((unsigned int)time(NULL));
  int n = rand()%12;
  cout << "n = " << n << endl;
  vector<int> r = countBits(n);
  print_array(r);
}
