#include "leetcode.hpp"

void test_hIndex() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  vector<int> citations;
  gen_array(n, citations);
  print_array(citations);
  cout << "hIndex = " << hIndex(citations) << endl;
}
