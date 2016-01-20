#include "leetcode.hpp"

/*
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * return
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
 */
void pathSumHelper(TreeNode *root, vector<vector<int> > &r, vector<int> res, int &sum, int val = 0) {
    if( root == NULL )
        return;
    val += root->val;
    res.push_back(root->val);
    if( val == sum )
        if( root->left == NULL && root->right == NULL ) {
            r.push_back(res);
            return;
        }
    pathSumHelper(root->left, r, res, sum, val);
    pathSumHelper(root->right, r, res, sum, val);
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > r;
    vector<int> res;
    pathSumHelper(root, r, res, sum);
    return r;
}
