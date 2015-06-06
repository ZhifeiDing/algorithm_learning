#include "leetcode.hpp"

/* recursive method
 */
bool hasPathSum_recursive(TreeNode* root, int sum) {
     if( !root ) return false;
     if( !root->left && !root->right && root->val == sum ) return true;
     return hasPathSum_recursive(root->left, sum - root->val) || hasPathSum_recursive(root->right, sum - root->val);
}

/*
 * iterative way -- dfs
 */
bool hasPathSum_dfs(TreeNode* root, int sum) {
    stack<pair<TreeNode*, int> > s;
    s.push(make_pair(root, sum));
    
    while( !s.empty() ) {
        root = s.top().first;
        sum = s.top().second;
        s.pop();
        
        if( !root ) break;
        if( !root->left && !root->right && root->val == sum ) return true;
        
        if( root->right ) s.push(make_pair(root->right, sum - root->val));
        if( root->left ) s.push(make_pair(root->left, sum - root->val));
        
    }
    return false;
}
