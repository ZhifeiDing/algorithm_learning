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
#include<unordered_set>
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

class ListNode {
  public:
    int val;
    ListNode* next;
    explicit ListNode() {};
    explicit ListNode(int x) : val(x) {};
    explicit ListNode(int x,ListNode* l) : val(x),next(l) {};
};

void print_list(ListNode* p, const string & s = "");
void gen_list(int n, ListNode* p,bool sorted = false);

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

void test_NumArray();

vector<int> findMinHeightTrees(int n, vector<pair<int, int> > edges);
void test_findMinHeightTrees();

vector<int> countSmaller(vector<int> &nums);
vector<int> countSmaller_insertSort(vector<int> &nums);
vector<int> countSmaller_BST(vector<int> &nums);
void test_countSmaller();

vector<vector<int> > zigzagLevelOrder(TreeNode* root);
void test_zigzagLevelOrder();

vector<vector<int> > levelOrder(TreeNode *root);
void test_levelOrder();

int minDepth(TreeNode *root);
void test_minDepth();
int minDepth_recursive(TreeNode *root);

int maxDepth_recursive(TreeNode *root);
int maxDepth(TreeNode *root);
void test_maxDepth();

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder);
void test_buildTree();

TreeNode* buildTreeI(vector<int> &preorder, vector<int> &inorder);
void test_buildTreeI();

TreeNode* sortedArrayToBST(vector<int> &nums);
TreeNode* sortedArrayToBST_iterative(vector<int> &nums);
void test_sortedArrayToBST();

TreeNode* sortedListToBST(ListNode* head);
void test_sortedListToBST();

vector<vector<int> > verticalOrder(TreeNode* root);
void test_verticalOrder();
#endif

