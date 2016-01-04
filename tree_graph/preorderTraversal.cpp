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
  if( root )
    s.push(root);

  while( !s.empty() ) {
    root = s.top();
    s.pop();
    r.push_back(root->val);

    if( root->right != NULL ) {
      s.push(root->right);
    } 
    if( root->left != NULL ) {
      s.push(root->left);
    } 
  }
  return r;
}

vector<int> preorderTraversal_morris(TreeNode* root) {
  vector<int> r;

  while( root ) {
    if( root->left == NULL ) {
      r.push_back(root->val);
      root = root->right;
    } else {
      TreeNode *pre = root->left;

      while( pre->right && pre->right != root )
        pre = pre->right;

      if( pre->right == NULL ) {
        r.push_back(root->val);
        pre->right = root;
        root = root->left;
      } else {
        pre->right = NULL;
        root = root->right;
      }
    }
  }
  return r;
}
