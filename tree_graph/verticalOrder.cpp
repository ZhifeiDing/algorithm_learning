#include "leetcode.hpp"

/*
 * Given a binary tree, return the vertical order traversal of its
 * nodes' values. (ie, from top to bottom, column by column).
 *
 * If two nodes are in the same row and column, the order should be
 * from left to right.
 *
 * Examples:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its vertical order traversal as:
 * [
 *   [9],
 *   [3,15],
 *   [20],
 *   [7]
 * ]
 * Given binary tree [3,9,20,4,5,2,7],
 *     _3_
 *    /   \
 *   9    20
 *  / \   / \
 * 4   5 2   7
 * return its vertical order traversal as:
 * [
 *   [4],
 *   [9],
 *   [3,5,2],
 *   [20],
 *   [7]
 * ]
 */

void findMinMaxDist(TreeNode *root, int &left, int &right, int hd) {
    if( root == NULL )
        return;
    if( hd < left )
        left = hd;
    if( right < hd )
        right = hd;
    findMinMaxDist(root->left, left, right, hd-1);
    findMinMaxDist(root->right, left, right, hd+1);
}

void getVerticalOrder(TreeNode *root, vector<vector<int> > &r, int left, int hd) {
    if( root == NULL )
        return;
    r[hd-left].push_back(root->val);
    getVerticalOrder(root->left, r, left, hd-1);
    getVerticalOrder(root->right, r, left, hd+1);
}

vector<vector<int> > verticalOrder(TreeNode* root) {
  int left = 0, right = 0;
  findMinMaxDist(root, left, right, 0);
  vector<vector<int> > r(right-left+1,vector<int>());
  getVerticalOrder(root, r, left, 0);
  return r;
}
