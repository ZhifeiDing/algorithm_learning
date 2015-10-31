#include "leetcode.hpp"

void test_getHint() {
  srand((unsigned int)time(NULL));
  int data = rand()%9000 + 1000;
  string secret = to_string(data);
  string guess = to_string(rand()%9000 + 1000);
  string r = getHint(secret, guess);
  cout << secret << endl << guess << endl << r << endl;
}
