#include "leetcode.hpp"

/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 */

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
  vector<vector<int> > r;
  queue<TreeNode*> q;

  q.push(root);
  bool flip = false;

  while( !q.empty() ) {
    vector<int> level;
    queue<TreeNode*> nextQ;
    while( !q.empty() ) {
      root = q.front();
      q.pop();
      level.push_back(root->val);
      if( root->left  ) nextQ.push(root->left);
      if( root->right ) nextQ.push(root->right);
    }
    if( flip )
      reverse(level.begin(), level.end());
    flip = !flip;
    q = nextQ;
    r.push_back(level);
  }

  return r;
}
