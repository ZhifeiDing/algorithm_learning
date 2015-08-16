#include "leetcode.hpp"
/*
 * Given a binary tree, imagine yourself standing on the right side of it, 
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * For example:
 * Given the following binary tree,
 *    1            <---
 *  /   \
 * 2     3         <---
 *  \     \
 *   5     4       <---
 * You should return [1, 3, 4].
 */

vector<int> rightSideView(TreeNode* root) {
  vector<int> r;
  if( root == NULL )
    return r;
  queue<TreeNode*> q;
  q.push(root);
  while( !q.empty() ) {
    root = q.front();
    r.push_back(root->val);

    queue<TreeNode*> t;
    while( !q.empty() ) {
      root = q.front();
      q.pop();
      if( root->right != NULL )
        t.push(root->right);
      if( root->left != NULL )
        t.push(root->left);
    }
    q = t;
  }
  return r;
}
