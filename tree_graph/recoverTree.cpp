#include "leetcode.hpp"
/*
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 */

void recoverTreeHelper(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second) {
    if( root == NULL )
        return;
    recoverTreeHelper(root->left, prev, first, second);

    if( prev && prev->val >= root->val ) {
        if( first == NULL )
            first = prev;
        second = root;
    }
    prev = root;
    recoverTreeHelper(root->right, prev, first, second);
}

void recoverTree(TreeNode* root) {
    TreeNode *first = NULL, *second = NULL, *prev = NULL;
    recoverTreeHelper(root, prev, first, second);
    swap(first->val, second->val);
}

void recoverTree_iterative(TreeNode* root) {
    TreeNode *first = NULL, *second = NULL, *prev = NULL;
    while( root ) {
        if( root->left ) {
            TreeNode *t = root->left;
            while( t->right && t->right != root )
                t = t->right;
            if( t->right == NULL ) {
                t->right = root;
                root = root->left;
                continue;
            } else {
                t->right = NULL;
            }
        }
        if( prev && prev->val >= root->val ) {
            if( first == NULL )
                first = prev;
            second = root;
        }
        prev = root;
        root = root->right;
    }
    swap(first->val, second->val);
}