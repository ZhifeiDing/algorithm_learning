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

using namespace std;

void gen_array(int n, vector<int> & data, int base = 97);
void print_array(vector<int> & data, const string & s = "Original");
void gen_string(string & s, int n , bool strict );
void print_string(string & s);

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
void test_uniquePathsWithObstacles();

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


void print_tree(TreeNode *root, const string &s = "Tree = ");

int numDistinct(string s, string t);
void test_numDistinct(void);

bool canJump(vector<int>& nums);
bool canJump_start(vector<int>& nums);
void test_canJump(void);

int maxProfit(vector<int>& prices);
void test_maxProfit(void);

bool isInterleave(string s1, string s2, string s3);
void test_isInterleave(void);

int rob(vector<int>& nums);
void test_rob();

int robII(vector<int>& nums);
void test_robII();

int maximalSquare(vector<vector<char> > & matrix);
void test_maximalSquare();

vector<int> diffWaysToCompute(string input);
void test_diffWaysToCompute();
vector<int> diffWaysToCompute_DP(string input);

string shortestPalindrome(string s);
void test_shortestPalindrome();

int numSquares(int n);
void test_numSquares();

int longestValidParentheses(string s);
void test_longestValidParentheses();
int longestValidParentheses_twopass(string s);

int lengthOfLIS(vector<int> &nums);
void test_lengthOfLIS();
int lengthOfLIS_lowerbound(vector<int> &nums);
int lengthOfLIS_bs(vector<int> &nums);

void test_NumArray();
void test_NumMatrix();

int maxProfitCoolDown(vector<int> & prices);
void test_maxProfitCoolDown();
int maxProfitCoolDown_novector(vector<int> & prices);

int maxCoins(vector<int> &nums);
void test_maxCoins();
int maxCoins_dc(vector<int> &nums);

int maxProfitII(vector<int> &prices);
void test_maxProfitII();

int maxProfitIII(vector<int> &prices);
void test_maxProfitIII();

int maxProfitVI(int k, vector<int> &prices);
void test_maxProfitVI();

int numTrees(int n);
void test_numTrees();

int numDecodings(string s);
void test_numDecodings();

int integerBreak(int n);
int integerBreak_DP(int n);
void test_integerBreak();

int robVI(TreeNode* root);
void test_robVI();

vector<int> countBits(int num);
void test_countBits();

int coinChange(vector<int> &coins, int amount);
void test_coinChange();

#endif

