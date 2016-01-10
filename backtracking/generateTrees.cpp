#include "leetcode.hpp"

/*
 * Given n, generate all structurally unique BST's (binary search trees)
 * that store values 1...n.
 * 
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */
vector<TreeNode*> generateTreesHelper(int left, int right) {

  vector<TreeNode*> r;
  if( left > right ) {
    r.push_back(NULL);
    return r;
  }
  for(int i = left; i <= right; ++i) {
    for(auto leftNode : generateTreesHelper(left, i-1))
      for(auto rightNode : generateTreesHelper(i+1, right)) {
        TreeNode *root = new TreeNode(i);
        root->left = leftNode;
        root->right = rightNode;
        r.push_back(root);
      }
  }
  return r;
}

vector<TreeNode*> generateTrees(int n) {
  if( n == 0 )
    return vector<TreeNode*>();
 return generateTreesHelper(1,n); 
}
