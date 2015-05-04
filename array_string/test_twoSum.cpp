#include "leetcode.hpp"

void test_twoSum(void) {
  vector<int> numbers;
  gen_array(7, numbers);
  print_array(numbers);
  int i = rand() % 7;
  int j = rand() % 7;
  while( i == j ) {
    j = rand() % 7;
  }
  int target = numbers[i] + numbers[j];
  //cout << numbers[i] << "+" << numbers[j] << "=" << target << endl;
  vector<int> r = twoSum(numbers,target);
  cout << numbers[r[0]-1] << "+" << numbers[r[1]-1] << "=" << target << endl;
  r = twoSum_hash(numbers, target);
  cout << numbers[r[0]-1] << "+" << numbers[r[1]-1] << "=" << target << endl;
}

