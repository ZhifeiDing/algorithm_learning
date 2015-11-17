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

using namespace std;

void gen_array(int n, vector<int> & data, int base = 97, bool positive = true);
void print_array(vector<int> & data, const string s = "Data");
void gen_string(string & s, int n , bool strict );
void print_string(string & s);



class ListNode {
  public:
    int val;
    ListNode* next;
    explicit ListNode() {};
    explicit ListNode(int x) : val(x) {};
    explicit ListNode(int x,ListNode* l) : val(x),next(l) {};
};

void test_combinationSum(void);
vector<vector<int>> combinationSum(vector<int>& candidates, int target);

vector<vector<int>> threeSum(vector<int>& nums);
void test_threeSum(void);
vector<vector<int>> threeSum_twoPointers(vector<int>& nums);

vector<vector<int> > combinationSum3(int k, int n);
void test_combinationSum3();

void test_WordDictionary();

vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
void test_findWords();

int threeSumClosest(vector<int> & nums, int target);
void test_threeSumClosest();

int numIslands(vector<vector<char>>& grid);
void test_numIslands();
int numIslands_uf(vector<vector<char> > & grid);

vector<vector<int>> subsetsWithDup(vector<int>& nums);
void test_subsetsWithDup();
vector<vector<int>> subsetsWithDup_linear(vector<int>& nums);

vector<string> restoreIpAddresses(string s);
void test_restoreIpAddresses();

vector<string> addOperators(string num, int target);
void test_addOperators();

vector<string> letterCombinations(string digits);
void test_letterCombinations();

vector<string> generateParenthesis(int n);
void test_generateParenthesis();

void gameOfLife(vector<vector<int> > &board);
void test_gameOfLife();

void setZeroes(vector<vector<int>>& matrix);
void test_setZeroes();

vector<vector<int> > fourSum(vector<int>& nums, int target);
void test_fourSum();

vector<string> removeInvalidParentheses(string s);
void test_removeInvalidParentheses();
#endif

