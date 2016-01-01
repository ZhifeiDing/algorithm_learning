#include "leetcode.hpp"

/*
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,3,2].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

// recursive solution : got TLE in OJ
void inorderTraversalHelper(TreeNode* root, vector<int> &r) {

  if( root == NULL )
    return;

  inorderTraversalHelper(root->left, r);
  r.push_back(root->val);
  inorderTraversalHelper(root->right, r);
}

vector<int> inorderTraversal(TreeNode* root) {
  vector<int> r;
  inorderTraversalHelper(root, r);
  return r;
}

vector<int> inorderTraversal_iterative(TreeNode* root) {
  vector<int> r;

  stack<TreeNode*> s;

  while( !s.empty() || root ) {
    if( s.empty() || root != NULL ) {
      s.push(root);
      root = root->left;
    } else {
      root = s.top();
      s.pop();

      r.push_back(root->val);
      root = root->right;
    }
  }
  return r;
}
