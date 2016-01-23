#include "leetcode.hpp"

TreeNode *upsideDownBinaryTree(TreeNode *root) {
    stack<TreeNode*> s;
    while(root) {
        s.push(root);
        root = root->left;
    }

    if( s.empty() )
        return NULL;
    TreeNode *p = s.top();
    s.pop();

    root = p;
    while( !s.empty() ) {
        root->right = s.top();
        root->left = s.top()->right;
        root->right->left = NULL;
        root->right->right = NULL;
        s.pop();
        root = root->left;
    }
    return p;
}