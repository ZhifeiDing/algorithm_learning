#include "leetcode.hpp"

void test_buildTree() {
  /*
   *        5
   *      /   \
   *     4     8
   *    /     / \
   *   11    13  4
   *  /  \        \
   * 7    2        1
   *
   */
  vector<int> inorder = {7,11,2,4,5,13,8,4,1};
  vector<int> postorder = {7,2,11,4,13,1,4,8,5};
  TreeNode *root = buildTree(inorder, postorder);

  vector<vector<int> > r = levelOrder(root);
  cout << "level order = " << endl;
  for(int i = 0; i < r.size(); ++i) {
    for(auto j : r[i])
      cout << j << "\t";
    cout << endl;
  }
}
