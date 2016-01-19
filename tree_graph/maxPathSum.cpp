#include "leetcode.hpp"

/*
 * Given a binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of
 * nodes from some starting node to any node in the tree along
 * the parent-child connections. The path does not need to go
 * through the root.
 *
 * For example:
 * Given the below binary tree,
 *
 *        1
 *       / \
 *      2   3
 * Return 6.
 */
int maxPathSumHelper(TreeNode *root, int &d) {
  if( root == NULL )
    return 0;
  int left = max(0, maxPathSumHelper(root->left, d));
  int right = max(0, maxPathSumHelper(root->right, d));
  d = max(d, left+right+root->val);
  return max(left,right)+root->val;
}

int maxPathSum(TreeNode* root) {
    int d = INT_MIN;
    maxPathSumHelper(root, d);
    return d;
}
