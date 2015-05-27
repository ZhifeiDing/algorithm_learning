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
void gen_string(string & s, int n , bool strict );
void print_string(string & s);

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
      //TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

vector<vector<int> > levelOrderBottom(TreeNode* root);
void test_levelOrderBottom(void);

void test_sumNumbers(void);
int sumNumbers(TreeNode* root);

#endif

