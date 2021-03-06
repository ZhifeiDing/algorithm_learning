#ifndef __LEETCODE_HPP__
#define __LEETCODE_HPP__

#include<functional>
#include<climits>
#include<vector>
#include<list>
#include<iostream>
#include<locale>
#include<ctime>
#include<utility>
#include<unordered_map>
#include<unordered_set>
#include<set>
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

struct TreeLinkNode {
    int val;
   TreeLinkNode *left;
   TreeLinkNode *right;
   TreeLinkNode *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
   TreeLinkNode(int x, TreeLinkNode *l, TreeLinkNode *r, TreeLinkNode *n) : val(x), left(l), right(r), next(n) {}
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

void print_tree(TreeNode *root, const string &s = "Tree = ");

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
TreeNode* sortedListToBST_n(ListNode* head);

vector<vector<int> > verticalOrder(TreeNode* root);
void test_verticalOrder();

vector<int> inorderTraversal(TreeNode* root);
void test_inorderTraversal();
vector<int> inorderTraversal_iterative(TreeNode* root);
vector<int> inorderTraversal_morris(TreeNode* root);

vector<int> preorderTraversal(TreeNode* root);
void test_preorderTraversal();
vector<int> preorderTraversal_iterative(TreeNode* root);
vector<int> preorderTraversal_morris(TreeNode* root);


vector<int> postorderTraversal(TreeNode* root);
void test_postorderTraversal();
vector<int> postorderTraversal_iterative(TreeNode* root);
vector<int> postorderTraversal_morris(TreeNode* root);

int maxPathSum(TreeNode* root);
void test_maxPathSum();

void flatten(TreeNode* root);
void test_flatten();
void flatten_iterative(TreeNode* root);

bool isValidBST(TreeNode* root);
void test_isValidBST();

void recoverTree(TreeNode* root);
void test_recoverTree();
void recoverTree_iterative(TreeNode* root);

bool isSymmetric(TreeNode *root);
void test_isSymmetric();
bool isSymmetric_iterative(TreeNode *root);

int closestValue(TreeNode *root, double target);
void test_closestValue();

vector<vector<int> > pathSum(TreeNode *root, int sum);
void test_pathSum();

TreeNode *upsideDownBinaryTree(TreeNode *root);
void test_upsideDownBinaryTree();

int longestConsecutive(TreeNode *root);
void test_longestConsecutive();

bool validTree(int n, vector<pair<int,int> > &edges);
void test_validTree();

bool isValidSerialization(string preorder);
void test_isValidSerialization();

vector<string> findItinerary(vector<pair<string,string> > &tickets);
void test_findItinerary();

void connect(TreeLinkNode *root);
void test_connect();

void connectII(TreeLinkNode *root);
void test_connectII();

int longestIncreasingPath(vector<vector<int> > &matrix);
void test_longestIncreasingPath();
int longestIncreasingPath_lambda(vector<vector<int> > &matrix);
int longestIncreasingPath_iterative(vector<vector<int> > &matrix);
#endif

