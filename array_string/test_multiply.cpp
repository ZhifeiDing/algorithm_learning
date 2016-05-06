#include "leetcode.hpp"

void test_multiply() {
  string num1, num2;
  srand((unsigned int)time(NULL));
  int n = rand() % 100000;
  int m = rand() % 100000;
  num1 = to_string(n);
  num2 = to_string(m);
  //num1 = "3";
  //num2 = "4";
  string r = multiply(num1, num2);
  cout << num1 << " * " << num2 << " = " << r << endl;
}
