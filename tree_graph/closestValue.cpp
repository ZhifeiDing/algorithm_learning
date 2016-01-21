#include "leetcode.hpp"

/*
 * Given a non-empty binary search tree and a target value, find the value
 * in the BST that is closest to the target.
 * Note:
 * Given target value is a floating point.
 * You are guaranteed to have only one unique value in the BST that is closest
 * to the target.
 */

int closestValue(TreeNode *root, double target) {
    int pre = root->val;

    while( root ) {
        if( abs(target - pre) > abs(target - root->val) )
            pre = root->val;
        if( target < root->val ) {
            root = root->left;
        } else if( root->val < target ) {
            root = root->right;
        }
    }
    return pre;
}