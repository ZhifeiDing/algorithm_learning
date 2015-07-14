#include "leetcode.hpp"

/*
 * Given a binary tree, find the lowest common ancestor (LCA) of two given 
 * nodes in the tree.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common 
 * ancestor is defined between two nodes v and w as the lowest node in T 
 * that has both v and w as descendants (where we allow a node to be a 
 * descendant of itself).”
 * 
 *         _______3______
 *        /              \
 *    ___5__          ___1__
 *   /      \        /      \
 *  6      _2       0       8
 *        /  \
 *       7   4
 * For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. 
 * Another example is LCA of nodes 5 and 4 is 5, since a node can be a 
 * descendant of itself according to the LCA definition.
 */

TreeNode* dfs(TreeNode* root, TreeNode* &p, TreeNode* &q) {
        bool retRoot=false; // true means only one of p and q is found in the left subtree 
        if(!root) return root;
        TreeNode* res;
        res = dfs(root->left, p, q); // search the left subtree
        if(!p && !q) return res; // if found both p and q, return the root when they are found first time
        if (!p || !q) retRoot = true; // check if one of p and q is found in the left tree
        res = dfs(root->right, p, q); // search the right subtree
        if(!p && !q)  // if we found both p and q
        /* if one is in the left subtree and the other is in the right 
         * subtree, return root, otherwise both of them are in the right 
         * subtree, so return the root when they first time are found
         */
            return  retRoot?root:res; 
                                                                                    if(root==p) p =nullptr;  // check whether root is p or q
        else if (root==q) q=nullptr;

        return root;
}
TreeNode* lowestCommonAncestorBT(TreeNode* root, TreeNode* p, TreeNode* q) {
  return dfs(root, p, q);
}
