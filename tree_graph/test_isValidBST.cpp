#include "leetcode.hpp"

void test_isValidBST() {
  TreeNode ll4(7);
  TreeNode lr4(2);
  TreeNode rr4(1);

  TreeNode ll3(11, &ll4,&lr4);
  TreeNode rl3(13);
  TreeNode rr3(4,NULL,&rr4);

  TreeNode l2(4,&ll3,NULL);
  TreeNode r2(8,&rl3, &rr3);
  TreeNode root(5, &l2,&r2);

  print_tree(&root);
  string r = isValidBST(&root) ? " is Valid BST" : " is not Valid BST";
  cout << r << endl;

  root.left->right = NULL;
  root.left->left = NULL;
  root.right->left = NULL;
  root.right->right = NULL;

  cout << endl;
  print_tree(&root);
  r = isValidBST(&root) ? " is Valid BST" : " is not Valid BST";
  cout << r << endl;
}
