#include "leetcode.hpp"

void test_maxDepth() {

  TreeNode ll4(7);
  TreeNode lr4(2);
  TreeNode rr4(1);

  TreeNode ll3(11, &ll4,&lr4);
  TreeNode rl3(13);
  TreeNode rr3(4,NULL,&rr4);

  TreeNode l2(4,&ll3,NULL);
  TreeNode r2(8,&rl3, &rr3);
  TreeNode root(5, &l2,&r2);

  int r = maxDepth(&root);
  cout << "max depth = " << r << endl;
  cout << "max depth = " << maxDepth_recursive(&root) << endl;
}
