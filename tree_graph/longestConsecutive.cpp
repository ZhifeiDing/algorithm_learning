#include "leetcode.hpp"
/*
 *Given a binary tree, find the length of the longest consecutive sequence path.
 *The path refers to any sequence of nodes from some starting node to any node
 in the tree along the parent-child connections. The longest consecutive path
 need to be from parent to child (cannot be the reverse).
 *For example,
 *   1
 *    \
 *     3
 *    / \
 *   2   4
 *        \
 *         5
 *Longest consecutive sequence path is 3-4-5, so return 3.
 *   2
 *    \
 *     3
 *    /
 *   2
 *  /
 * 1
 *Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
 */
int longestConsecutiveHelper(TreeNode *root, int longestSeq) {
    if( root->left == NULL && root->right == NULL )
        return longestSeq;
    int leftLongest = 0;
    if( root->left ) {
        if( root->val + 1 == root->left->val ) {
            leftLongest = longestConsecutiveHelper(root->left, longestSeq+1);
        } else {
            leftLongest = longestConsecutiveHelper(root->left, longestSeq);
        }
    }
    int rightLongest = 0;
    if( root->right ) {
        if( root->val + 1 == root->right->val ) {
            rightLongest = longestConsecutiveHelper(root->right, longestSeq+1);
        } else {
            rightLongest = longestConsecutiveHelper(root->right, longestSeq);
        }
    }
    return max(leftLongest, rightLongest);
}

int longestConsecutive(TreeNode *root) {
    if( root == NULL )
        return 0;
    return longestConsecutiveHelper(root, 0) + 1;
}