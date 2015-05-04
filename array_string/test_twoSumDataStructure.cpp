#include "leetcode.hpp"

void test_twoSumDataStructure(void) {
  srand((unsigned int)time(NULL));
  int r = rand() % 47;
  twoSumADT_hash n(r);
  twoSumADT_hash m(r);
  r = rand() % 47;
  n.add(r);
  m.add(r);
  r = rand() % 47;
  n.add(r);
  m.add(r);
  r = rand() % 47;
  n.add(r);
  m.add(r);
  r = rand() % 47;
  n.add(r);
  m.add(r);
  n.print();
  m.print();
  r = rand() % 47;
  cout << "n.find(" << r << ") = " << n.find(r) << endl;
  cout << "m.find(" << r << ") = " << m.find(r) << endl;
  r = rand() % 47;
  cout << "n.find(" << r << ") = " << n.find(r) << endl;
  cout << "m.find(" << r << ") = " << m.find(r) << endl;
}
