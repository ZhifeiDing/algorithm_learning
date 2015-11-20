#include "leetcode.hpp"

void test_isAdditiveNumber() {
  string num = "112358"; // true
  cout << num << ( isAdditiveNumber(num) ? " is additive number" : " is not additive number" ) << endl;

  num = "199100199"; // true
  cout << num << ( isAdditiveNumber(num) ? " is additive number" : " is not additive number" ) << endl;

  num = "123"; // true
  cout << num << ( isAdditiveNumber(num) ? " is additive number" : " is not additive number" ) << endl;

  num = to_string(rand()); // random
  cout << num << ( isAdditiveNumber(num) ? " is additive number" : " is not additive number" ) << endl;
}
