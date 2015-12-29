#include "leetcode.hpp"

/*
 * Given inorder and preorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */

TreeNode* buildTreeIHelper(vector<int> &preorder, int preorderLeft, int preorderRight, vector<int> &inorder, int inorderLeft, int inorderRight) {
  if( inorderLeft > inorderRight )
    return NULL;

  TreeNode *root = new TreeNode(preorder[preorderLeft]);
  if( inorderLeft == inorderRight )
    return root;

  // locate the root in inorder
  int rootIdx = 0;
  while( inorder[inorderLeft+rootIdx] != preorder[preorderLeft] )
    ++rootIdx;

  root->left = buildTreeIHelper(preorder, preorderLeft + 1, preorderLeft + rootIdx, inorder, inorderLeft, inorderLeft + rootIdx - 1);
  root->right = buildTreeIHelper(preorder, preorderLeft + rootIdx + 1, preorderRight, inorder, inorderLeft + rootIdx + 1, inorderRight);

  return root;
}

TreeNode* buildTreeI(vector<int> &preorder, vector<int> &inorder) {
  return buildTreeIHelper( preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}
