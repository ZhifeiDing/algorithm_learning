#include "leetcode.hpp"

void test_levelOrderBottom(void) {
  TreeNode root(1);
  TreeNode left1(2);
  TreeNode right1(3);
  TreeNode left2(4);
  TreeNode right2(5);
  root.left = &left1;
  root.right = &right1;
  left1.left = &left2;
  left1.right = &right2;
  vector<vector<int> > r = levelOrderBottom(&root);
  print_2d_array(r);
}
