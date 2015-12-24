#include "leetcode.hpp"

/*
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */

TreeNode* buildTreeHelper(vector<int> &inorder, int inorderLeft, int inorderRight, vector<int> &postorder, int postorderLeft, int postorderRight) {
  if( inorderLeft > inorderRight )
    return NULL;

  TreeNode *root = new TreeNode(postorder[postorderRight]);
  if( inorderLeft == inorderRight )
    return root;

  // locate the root in inorder
  int rootIdx = 0;
  while( inorder[inorderLeft+rootIdx] != postorder[postorderRight] )
    ++rootIdx;

  root->left = buildTreeHelper(inorder, inorderLeft, inorderLeft + rootIdx - 1, postorder, postorderLeft, postorderLeft + rootIdx -1);
  root->right = buildTreeHelper(inorder, inorderLeft + rootIdx + 1, inorderRight, postorder, postorderLeft + rootIdx, postorderRight - 1);

  return root;
}

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
  return buildTreeHelper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}
