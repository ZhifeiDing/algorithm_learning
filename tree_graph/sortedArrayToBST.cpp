#include "leetcode.hpp"

/*
 * Given an array where elements are sorted in ascending order, 
 * convert it to a height balanced BST.
 */

TreeNode* sortedArrayToBSTHelper(vector<int> &nums, int left, int right) {
  if( left > right )
    return NULL;
  int idx = left + ceil(float( right -left ) / 2);
  TreeNode *root = new TreeNode(nums[idx]);
  root->left = sortedArrayToBSTHelper(nums, left, idx-1);
  root->right = sortedArrayToBSTHelper(nums, idx+1, right);
  return root;
}

TreeNode* sortedArrayToBST(vector<int> &nums) {
  return sortedArrayToBSTHelper(nums, 0, nums.size()-1);
}

TreeNode* sortedArrayToBST_iterative(vector<int> &nums) {
  TreeNode *root = new TreeNode(-1);
  TreeNode *p = root;

  if( nums.empty() )
    return NULL;

  queue<tuple<TreeNode*, int, int> > q;
  q.push(make_tuple(p, 0, nums.size()-1));

  while( !q.empty() ) {
    int left, right;
    tie(p, left, right) = q.front();
    q.pop();
    if( left > right )
      continue;

    int idx = left + ceil(float(right - left)/2);
    p->val = nums[idx];
    if( left < idx ) {
      p->left = new TreeNode(-1);
      q.push(make_tuple(p->left, left, idx-1));
    }
    if( idx < right ) {
      p->right = new TreeNode(-1);
      q.push(make_tuple(p->right, idx+1, right));
    }
  }

  return root;
}
