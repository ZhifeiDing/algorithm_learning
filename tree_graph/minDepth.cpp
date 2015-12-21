#include "leetcode.hpp"

/*
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path 
 * from the root node down to the nearest leaf node.
 */

int minDepth(TreeNode *root) {

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
      if( root->left == NULL && root->right == NULL )
        return level;
      if( root->left ) q.push(root->left);
      if( root->right ) q.push(root->right);
    }
  }

  return level;
}
