#include "leetcode.hpp"

/*
 * Given a binary tree, return the bottom-up level order traversal of 
 * its nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 */

vector<vector<int> > levelOrderBottom(TreeNode* root) {
    vector<vector<int> > r;
    vector<int> level;
    queue<TreeNode*> q;
    queue<TreeNode*> l;
    if( !root ) return r;
    q.push(root);
    while( !q.empty() ) {
        root = q.front();
        q.pop();
        level.push_back(root->val);
        
        if( root->left ) 
            l.push(root->left);
            
        if( root->right )
            l.push(root->right);
        
        if( q.empty() ) {
            r.push_back(level);
            level.resize(0);
            //copy(l.begin(), l.end(), q.begin());
            while( !l.empty() ) {
                q.push(l.front());
                l.pop();
            }
        }
            
    }
    reverse(r.begin(),r.end());
    return r;
}
