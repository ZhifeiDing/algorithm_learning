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
  TreeNode *pre;

  while( !s.empty() || root ) {
    if( s.empty() || root != NULL ) {
      s.push(root);
      root = root->left;
    } else {
      root = s.top();

      if( !root->right || pre == root->right ) {
        r.push_back(root->val);
        s.pop();
        pre = root;
        root = NULL;
      } else {
        root = root->right;
      }
    }
  }
  return r;
}

void reverse(TreeNode *from, TreeNode *to) {
  if( from == to )
    return;
  TreeNode *cur = from, *next = from->right;

  while( true ) {
    TreeNode *t = cur;
    cur = next;
    next = next->right;
    cur->right = t;
    if( cur == to )
      break;
  }
}

void reverseGet(TreeNode *from, TreeNode *to, vector<int> &r) {
  reverse(from, to);
  TreeNode *cur = to;
  while(true) {
    r.push_back(cur->val);
    if( cur == from )
      break;
    cur = cur->right;
  } 
  reverse(to,from);
}

vector<int> postorderTraversal_morris(TreeNode* root) {
  vector<int> r;
  TreeNode dummy(-1);
  dummy.left = root;

  root = &dummy;

  while( root ) {
    if( root->left == NULL ) {
      root = root->right;
    } else {
      TreeNode *prev = root->left;

      while( prev->right && prev->right != root )
        prev = prev->right;

      if( prev->right == NULL ) {
        prev->right = root;
        root = root->left;
      } else {
        reverseGet(root->left, prev,r);
        prev->right = NULL;
        root = root->right;
      }
    }
  }
  return r;
}
