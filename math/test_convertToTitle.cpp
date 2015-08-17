#include "leetcode.hpp"

void test_convertToTitle() {
  srand((unsigned int)time(NULL));
  int n = rand()%510 + 1;
  string r = convertToTitle(n);
  cout << n << " 's Excel title = " << r << endl;
  int t = titleToNumber(r);
  cout << r << " 's Excel Number = " << t << endl;
}
