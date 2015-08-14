#include "leetcode.hpp"
/*
 * Invert a binary tree.
 * 
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 * to
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * Google: 90% of our engineers use the software you wrote (Homebrew), 
 * but you can’t invert a binary tree on a whiteboard so fuck off.
 */

TreeNode* invertTree(TreeNode* root) {
    TreeNode* r = root;
    queue<TreeNode*> q;
    if( !root ) return root;
    q.push(root);
    
    while(!q.empty()) {
        root = q.front();
        q.pop();
        
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;
        
        if( root->left ) 
            q.push(root->left);
        if( root->right )
            q.push(root->right);
    }
    return r;
}
