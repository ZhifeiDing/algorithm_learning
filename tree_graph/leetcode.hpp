#ifndef __LEETCODE_HPP__
#define __LEETCODE_HPP__

#include<climits>
#include<vector>
#include<list>
#include<iostream>
#include<locale>
#include<ctime>
#include<utility>
#include<unordered_map>
#include<algorithm>
#include<bitset>
#include<sstream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;

void gen_array(int n, vector<int> & data, int base = 97);
void print_array(vector<int> & data);
void print_2d_array(vector<vector<int> > & data);
void gen_string(string & s, int n , bool strict = true);
void print_string(string & s);

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
      TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

vector<vector<int> > levelOrderBottom(TreeNode* root);
void test_levelOrderBottom(void);

void test_sumNumbers(void);
int sumNumbers(TreeNode* root);

bool hasPathSum_recursive(TreeNode* root, int sum);
bool hasPathSum_dfs(TreeNode* root, int sum);
void test_hasPathSum(void);

void test_invertTree();
TreeNode* invertTree(TreeNode* root);

int kthSmallest(TreeNode* root, int k);
void test_kthSmallest();
int kthSmallest_iterative(TreeNode* root, int k);
void test_kthSmallest_iterative();

int countNodes(TreeNode* root);
void test_countNodes();

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
void test_lowestCommonAncestor();

TreeNode* lowestCommonAncestorBT(TreeNode* root, TreeNode* p, TreeNode* q);
void test_lowestCommonAncestorBT();

void test_Trie();

vector<int> rightSideView(TreeNode* root);
void test_rightSideView();

vector<string> binaryTreePaths(TreeNode* root);
vector<string> binaryTreePaths_recursive(TreeNode* root);
void test_binaryTreePaths();

vector<string> binaryTreePaths_recursive2(TreeNode* root);
#endif

