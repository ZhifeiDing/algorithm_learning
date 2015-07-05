#include "leetcode.hpp"

void test_kthSmallest() {
  srand((unsigned int)time(NULL));
  
  TreeNode root(4);
  TreeNode left1(2);
  TreeNode right1(5);
  TreeNode left2(1);
  TreeNode right2(3);
  root.left = &left1;
  root.right = &right1;
  left1.left = &left2;
  left1.right = &right2;
  int k = rand()%5 + 1;
  cout << k << "th element = " << kthSmallest(&root, k) << endl;
  cout << k << "th element = " << kthSmallest_iterative(&root, k) << endl;
}
