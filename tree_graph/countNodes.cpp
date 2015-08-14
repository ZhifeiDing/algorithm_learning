#include "leetcode.hpp"

/*
 * Given a complete binary tree, count the number of nodes.
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, 
 * is completely filled, and all nodes in the last level are as far 
 * left as possible. It can have between 1 and 2h nodes inclusive at 
 * the last level h.
 */
int countNodes(TreeNode* root) {
    if(!root) return 0;
    TreeNode* p = root;
    int height = 0;
    int result = 0;
    while(p->left) {height++; p = p->left;}
    long power = pow(2,height);
    int depth = 0;
    while (root->left) {
        if(!root->right) break;
        else {
            depth++;
            power /= 2;
            p = root->right;
            int count = depth;
            while(p->left) {p=p->left;count++;}
            if (count==height) {
                root = root->right;
                result += power;
            } else {
                root = root->left;
            }
        }
    }
    return result+pow(2, height);
}
