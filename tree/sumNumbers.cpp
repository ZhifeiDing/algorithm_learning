#include "leetcode.hpp"

/*
 * Given a binary tree containing digits from 0-9 only, each 
 * root-to-leaf path could represent a number.
 * 
 * An example is the root-to-leaf path 1->2->3 which represents 
 * the number 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * For example,
 * 
 *     1
 *    / \
 *   2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * 
 * Return the sum = 12 + 13 = 25.
 */

int sumNumbers(TreeNode* root) {
    int val = 0;
    if( !root ) return 0;
    
    vector<int> r;
    stack<pair<TreeNode*,int> > s;
    s.push(make_pair(root,0));
    while(!s.empty()) {
        root = s.top().first;
        val = s.top().second;
        s.pop();
        
        val = val * 10 + root->val;
        
        if( !root->left && !root->right )
            r.push_back(val);
        else {
          if( root->right )
            s.push(make_pair(root->right,val));
          if( root->left )
            s.push(make_pair(root->left,val));
        }
        
    }
    int sum = 0;
    for(int i = 0; i < r.size(); i++)
        sum += r[i];
    return sum;
}
