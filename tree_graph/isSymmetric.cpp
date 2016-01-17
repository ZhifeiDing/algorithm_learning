#include "leetcode.hpp"
/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *
 * For example, this binary tree is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 */

bool isSymmetricHelper(TreeNode *left, TreeNode *right) {
    if( left == NULL && right == NULL )
        return true;
    if( left == NULL ^ right == NULL )
        return false;
    return left->val == right->val && isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right,right->left);
}

bool isSymmetric(TreeNode *root) {
    if( root == NULL )
        return true;
    return isSymmetricHelper(root->left, root->right);
}
