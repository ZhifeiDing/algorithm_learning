#include "leetcode.hpp"

/*
 * Serialization is the process of converting a data structure 
 * or object into a sequence of bits so that it can be stored 
 * in a file or memory buffer, or transmitted across a network 
 * connection link to be reconstructed later in the same or another 
 * computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. 
 * There is no restriction on how your serialization/deserialization 
 * algorithm should work. You just need to ensure that a binary tree 
 * can be serialized to a string and this string can be deserialized 
 * to the original tree structure.
 * 
 * For example, you may serialize the following tree
 * 
 *     1
 *    / \
 *   2   3
 *      / \
 *     4   5
 * as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ 
 * serializes a binary tree. You do not necessarily need to follow this 
 * format, so please be creative and come up with different approaches 
 * yourself.
 * Note: Do not use class member/global/static variables to store states. 
 * Your serialize and deserialize algorithms should be stateless.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if( root == NULL )
            return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if( data.size() == 0 || data[0] == "#" )
          return (TreeNode*)NULL;
        stringstream ss(data);
        string s;
        getline(ss, s, ",");
        TreeNode root(stoi(s));
        TreeNode *p = &root;

        stack<TreeNode*> q;
        q.push(p);
      
        while( !q.empty() ) {
          p = q.top();
          q.pop();

          if( !getline(ss, s, ",") )
            break;
          if( s != "#" ) {
            p->left = new TreeNode(stoi(s));
            q.push(p->left);
          } else {
            if( !getline(ss,s,",") )
              break;
            if( s != "#" ) {
              p->right = new TreeNode(stoi(s));
              q.push(r);
              q.push(p->right);
            }
          }
        }

        return &root;

    }
};

class Codec_level {
public:
    string serialize(TreeNode* root) {

        /* for example, tree[1,2] results in: [[2]1[N]] */

        return root ? "["+serialize(root->left)+to_string(root->val)+serialize(root->right)+"]" : "[N]";
    }

    TreeNode* deserialize(string data) {
        if (data=="[N]") return NULL;

        /* for example above: [[2]1[N]], after while loops below, a=3, the index of ']' matching secnod '[',
         b=5, the index of [ matching ']' at len-2 */

        int len=data.length(), a, b, s=1, k=2;
        while (1) {
            if (data[k]=='[') s++;
            if (data[k]==']') s--;
            if (s==0) { a=k; break; }
            k++;
        }

        k=len-3, s=1;
        while (1) {
            if (data[k]=='[') s--;
            if (data[k]==']') s++;
            if (s==0) { b=k; break; }
            k--;
        }

        TreeNode *head = new TreeNode(atoi(data.substr(a+1, b-a-1).c_str()));
        head->left = deserialize(data.substr(1, a));
        head->right = deserialize(data.substr(b, len-2-b+1));
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
