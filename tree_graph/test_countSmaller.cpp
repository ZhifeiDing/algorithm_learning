#include "leetcode.hpp"

void test_countSmaller() {

  srand((unsigned int)time(NULL));
  int n = rand()%15;
  vector<int> nums;
  gen_array(n, nums);
  print_array(nums);
  vector<int> r = countSmaller_insertSort(nums);
  cout << "smaller number = " ;
  print_array(r);
  r = countSmaller_BST(nums);
  cout << "smaller number = " ;
  print_array(r);
}
