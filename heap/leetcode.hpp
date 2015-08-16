#ifndef __LEETCODE_HPP__
#define __LEETCODE_HPP__

#include<climits>
#include<vector>
#include<list>
#include<iostream>
#include<locale>
#include<ctime>
#include<utility>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<bitset>
#include<sstream>
#include<string>
#include<cstdlib>
#include<stack>

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

void test_Stack();

void test_MinStack();

void test_Queue();

vector<int> maxSlidingWindow(vector<int>& nums, int k);
void test_maxSlidingWindow();

vector<pair<int, int> > getSkyline(vector<vector<int>>& buildings);
void test_getSkyline();

int findKthLargest(vector<int> & nums, int k);
void test_findKthLargest();
int findKthLargest_minHeap(vector<int> & nums, int k);
#endif
