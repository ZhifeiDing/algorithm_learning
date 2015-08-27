#include "leetcode.hpp"

void test_binaryTreePaths() {
  TreeNode ll4(7);
  TreeNode lr4(2);
  TreeNode rr4(1);

  TreeNode ll3(11, &ll4,&lr4);
  TreeNode rl3(13);
  TreeNode rr3(4,NULL,&rr4);

  TreeNode l2(4,&ll3,NULL);
  TreeNode r2(8,&rl3, &rr3);
  TreeNode root(5, &l2,&r2);
  vector<string> r = binaryTreePaths_recursive(&root);
  for(auto i : r)
    cout << i << endl;
  cout << endl;
  r = binaryTreePaths_recursive2(&root);
  for(auto i : r)
    cout << i << endl;
  cout << endl;
}
