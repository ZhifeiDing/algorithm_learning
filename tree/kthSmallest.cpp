#include "leetcode.hpp"

/*
 * Given a binary search tree, write a function kthSmallest to find 
 * the kth smallest element in it.
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 * 
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and 
 * you need to find the kth smallest frequently? How would you optimize 
 * the kthSmallest routine?
 */
int cntElement(TreeNode* r, int c) {
  if( r == NULL ) return c;
  c = cntElement(r->left, ++c);
  return cntElement(r->right, c);
}

int kthSmallest(TreeNode* root, int k) {
  if( root == NULL ) return 0;
  int ll = cntElement(root->left, 0);
  if( k == ll + 1 )
    return root->val;
  else if( k < ll + 1 )
    return kthSmallest(root->left, k);
  else
    return kthSmallest(root->right, k -ll - 1);
}

int kthSmallest_iterative(TreeNode* root, int k) {
  stack<TreeNode*> s;
  while( !s.empty() || root ) {
    if( root ) {
      s.push(root);
      root = root->left;
    } else {
      root = s.top();
      s.pop();
      if( k-- == 1 )
        return root->val;
      else
        root = root->right;
    }
  }
}

