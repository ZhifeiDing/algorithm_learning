#include "leetcode.hpp"

void test_twoSumSort(void) {

  vector<int> numbers;
  gen_array(7, numbers);
  int i = rand() % 7;
  int j = rand() % 7;
  while( i == j ) {
    j = rand() % 7;
  }
  int target = numbers[i] + numbers[j];
  sort(numbers.begin(),numbers.end());
  print_array(numbers);
  vector<int> r = twoSumSort_binarySearch(numbers,target);
  cout << numbers[r[0]-1] << "+" << numbers[r[1]-1] << "=" << target << endl;
  r = twoSumSort_twoPointer(numbers,target);
  cout << numbers[r[0]-1] << "+" << numbers[r[1]-1] << "=" << target << endl;
}
