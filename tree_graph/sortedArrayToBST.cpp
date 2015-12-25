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
