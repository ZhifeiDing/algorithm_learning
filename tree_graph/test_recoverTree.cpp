#include "leetcode.hpp"

void test_recoverTree_iterative() {

  TreeNode ll4(1);
  TreeNode lr4(3);
  TreeNode rr4(11);

  TreeNode ll3(2, &ll4,&lr4);
  TreeNode rl3(7);
  TreeNode rr3(9,NULL,&rr4);

  TreeNode l2(8,&ll3,NULL);
  TreeNode r2(4,&rl3, &rr3);
  TreeNode root(6, &l2,&r2);

  print_tree(&root);
  recoverTree_iterative(&root);
  print_tree(&root);

}
void test_recoverTree() {

  TreeNode ll4(1);
  TreeNode lr4(3);
  TreeNode rr4(11);

  TreeNode ll3(2, &ll4,&lr4);
  TreeNode rl3(7);
  TreeNode rr3(9,NULL,&rr4);

  TreeNode l2(8,&ll3,NULL);
  TreeNode r2(4,&rl3, &rr3);
  TreeNode root(6, &l2,&r2);

  print_tree(&root);
  recoverTree(&root);
  print_tree(&root);

  test_recoverTree_iterative();

}
