#include "leetcode.hpp"

void test_hIndexII() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  vector<int> citations;
  gen_array(n, citations);
  sort(citations.begin(), citations.end());
  print_array(citations);
  cout << "hIndex = " << hIndexII(citations) << endl;
}
