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
void print_array(vector<int> & data);
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


int numDistinct(string s, string t);
void test_numDistinct(void);

bool canJump(vector<int>& nums);
bool canJump_start(vector<int>& nums);
void test_canJump(void);

vector<string> fullJustify(vector<string> &words, int maxWidth);
void test_fullJustify();

int minPatches(vector<int> &nums, int n);
void test_minPatches();

vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k);
void test_maxNumber();
#endif

