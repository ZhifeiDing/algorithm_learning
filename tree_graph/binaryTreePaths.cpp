#include "leetcode.hpp"

/*
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * For example, given the following binary tree:
 * 
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * All root-to-leaf paths are:
 * 
 * ["1->2->5", "1->3"]
 */

void binaryTreePathsHelper(TreeNode* root, vector<string> & r, string & s) {
  s.append(to_string(root->val));
  if( root->right == NULL && root->left == NULL ) {
    r.push_back(s);
    auto itr = s.find_last_of('>');
    s.resize(itr+1);
    return;
  }
  if( root->left != NULL ) {
    s.append("->");
    binaryTreePathsHelper(root->left, r, s);
    auto itr = s.find_last_of('>');
    s.resize(itr-1);
  }
  if( root->right != NULL ) {
    s.append("->");
    binaryTreePathsHelper(root->right, r, s);
    auto itr = s.find_last_of('>');
    s.resize(itr-1);
  }
}

vector<string> binaryTreePaths_recursive(TreeNode* root) {
  vector<string> r;
  string s;
  if( root == NULL )
    return r;
  binaryTreePathsHelper(root, r, s);
  return r;
}

void binaryTreePathsHelper2(TreeNode* root, vector<string> & r, string s) {
  if( s.size() )
    s.append("->");
  s.append(to_string(root->val));
  if( root->left == NULL && root->right == NULL ) {
    r.push_back(s);
    return;
  }
  if( root->left != NULL )
    binaryTreePathsHelper2(root->left, r, s);
  if( root->right != NULL )
    binaryTreePathsHelper2(root->right, r, s);
}

vector<string> binaryTreePaths_recursive2(TreeNode* root) {
  vector<string> r;
  string s;
  if(root == NULL )
    return r;
  binaryTreePathsHelper2(root, r, s);
  return r;
}
