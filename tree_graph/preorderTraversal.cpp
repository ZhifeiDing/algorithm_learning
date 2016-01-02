#include "leetcode.hpp"

/*
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,2,3].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

// recursive solution : got TLE in OJ
void preorderTraversalHelper(TreeNode* root, vector<int> &r) {

  if( root == NULL )
    return;

  r.push_back(root->val);
  preorderTraversalHelper(root->left, r);
  preorderTraversalHelper(root->right, r);
}

vector<int> preorderTraversal(TreeNode* root) {
  vector<int> r;
  preorderTraversalHelper(root, r);
  return r;
}

vector<int> preorderTraversal_iterative(TreeNode* root) {
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
