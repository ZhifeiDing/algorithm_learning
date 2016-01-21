#include "leetcode.hpp"

void test_closestValue() {
  TreeNode ll4(1);
  TreeNode lr4(3);
  TreeNode rr4(15);

  TreeNode ll3(2, &ll4,&lr4);
  TreeNode rl3(7);
  TreeNode rr3(12,NULL,&rr4);

  TreeNode l2(4,&ll3,NULL);
  TreeNode r2(8,&rl3, &rr3);
  TreeNode root(5, &l2,&r2);

  print_tree(&root);

  srand((unsigned int)time(NULL));
  double target = rand()%14 - 0.5;
  cout << "target = " << target << endl;
  cout << "the closest value = " << closestValue(&root, target) << endl;
}
