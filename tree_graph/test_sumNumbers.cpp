#include "leetcode.hpp"

void test_sumNumbers(void) {
  TreeNode left1(1);
  TreeNode right(3);
  TreeNode root(0);
  root.left = &left1;
  root.right = &right;
  cout << sumNumbers(&root) << endl;
}
