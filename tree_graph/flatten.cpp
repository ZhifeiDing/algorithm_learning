#include "leetcode.hpp"

/*
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example,
 * Given
 * 
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 * The flattened tree should look like:
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 * click to show hints.
 * 
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example,
 * Given
 * 
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 * The flattened tree should look like:
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 * 
 * Hints:
 * If you notice carefully in the flattened tree, each node's right 
 * child points to the next node of a pre-order traversal.
 */
// recursive solution
void flatten(TreeNode* root) {
  if( root == NULL )
    return;
  TreeNode *rootRight = root->right; 
  root->right = root->left;
  root->left = NULL;

  // attach the root's right to the left tree's right tree
  TreeNode *pre = root;
  while( pre->right )
    pre = pre->right;

  pre->right = rootRight;

  // now let's move to next node
  flatten(root->right);
}

// iterative solution

void flatten_iterative(TreeNode* root) {
  while( root ) {
    if( root->left ) {
      TreeNode *pre = root->left;
      while( pre->right )
        pre = pre->right;
      pre->right = root->right;
      root->right = root->left;
      root->left = NULL;
    }
    root = root->right;
  }
}
