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

void test_combinationSum(void);
vector<vector<int>> combinationSum(vector<int>& candidates, int target);

#endif

