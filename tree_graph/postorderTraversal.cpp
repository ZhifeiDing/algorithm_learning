#include "leetcode.hpp"

/*
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [3,2,1].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

// recursive solution : got TLE in OJ
void postorderTraversalHelper(TreeNode* root, vector<int> &r) {

  if( root == NULL )
    return;

  postorderTraversalHelper(root->left, r);
  postorderTraversalHelper(root->right, r);
  r.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
  vector<int> r;
  postorderTraversalHelper(root, r);
  return r;
}

vector<int> postorderTraversal_iterative(TreeNode* root) {
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

vector<int> postorderTraversal_morris(TreeNode* root) {
  vector<int> r;
  return r;
}
