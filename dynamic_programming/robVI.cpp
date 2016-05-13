#include "leetcode.hpp"
/*
 *
 *The thief has found himself a new place for his thievery again. There is
 *only one entrance to this area, called the "root." Besides the root, each
 *house has one and only one parent house. After a tour, the smart thief realized
 *that "all houses in this place forms a binary tree". It will automatically
 *contact the police if two directly-linked houses were broken into on the
 *same night.
 *
 *Determine the maximum amount of money the thief can rob tonight without
 *alerting the police.
 *
 *Example 1:
 *     3
 *    / \
 *   2   3
 *    \   \
 *     3   1
 *Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *Example 2:
 *     3
 *    / \
 *   4   5
 *  / \   \
 * 1   3   1
 *Maximum amount of money the thief can rob = 4 + 5 = 9.
 */
const pair<int,int> &robHelper(TreeNode* root) {
    if( root == nullptr )
        return make_pair(0,0);
    pair<int,int> leftVal = robHelper(root->left);
    pair<int,int> rightVal = robHelper(root->right);
    int robRootVal = root->val + leftVal.second + rightVal.second;
    int noRootVal = max(leftVal.first, leftVal.second) +
                    max(rightVal.second, rightVal.first);
    return make_pair(robRootVal, noRootVal);
}

int robVI(TreeNode* root) {
    const pair<int,int> r = robHelper(root);
    return max(r.first, r.second);
}