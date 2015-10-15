#include "leetcode.hpp"

void test_canWinNim() {
  srand((unsigned int)time(NULL));
  int n = rand()%120;
  string s = canWinNim(n) ? " can win " : " can't win ";
  cout << n << " : " << s << endl;
}
