#include "leetcode.hpp"

void test_addBinary() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  int m = rand()%11;
  string a, b;
  for(int i = 0; i < n; ++i) {
    a.push_back(rand()%2 + '0');
  }
  for(int i = 0; i < m; ++i) {
    b.push_back(rand()%2 + '0');
  }
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  string r = addBinary(a,b);
  cout << "a + b = " << r << endl;
}
