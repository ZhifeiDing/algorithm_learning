#include "leetcode.hpp"

/*
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest 
 * path from the root node down to the farthest leaf node.
 */

int maxDepth(TreeNode *root) {

  int level = 0;
  if( root == NULL )
    return 0;
  queue<TreeNode*> q;

  q.push(root);

  while( !q.empty() ) {
    int len = q.size();
    ++level;
    for(int i = 0; i < len; ++i) {
      root = q.front();
      q.pop();
      if( root->left ) q.push(root->left);
      if( root->right ) q.push(root->right);
    }
  }

  return level;
}

int maxDepth_recursive(TreeNode *root) {
  if( root == NULL )
    return 0;
  return 1 + max(maxDepth_recursive(root->left), maxDepth_recursive(root->right));
}
