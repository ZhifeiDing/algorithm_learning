#include "leetcode.hpp"

/*
 * Given a binary tree, return the level order traversal of 
 * its nodes' values. (ie, from left to right, level by level).
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 */

vector<vector<int> > levelOrder(TreeNode *root) {
  vector<vector<int> > r;
  if( root == NULL )
    return r;
  queue<TreeNode*> q;
  q.push(root);

  while( !q.empty() ) {
    int len = q.size();
    vector<int> level;
    for(int i = 0; i < len; ++i) {
      root = q.front();
      q.pop();
      level.push_back(root->val);
      if( root->left != NULL ) q.push(root->left);
      if( root->right!= NULL ) q.push(root->right);
    }
    r.push_back(level);
  }

  return r;
}
