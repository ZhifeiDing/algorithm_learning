#include "leetcode.hpp"

void test_numberToWords() {
  srand((unsigned int)time(NULL));
  int num = rand();
  string r = numberToWords(num);
  cout << num << " = " << endl;
  cout << r << endl;
}
