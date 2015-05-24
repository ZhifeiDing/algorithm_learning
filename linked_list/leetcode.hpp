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

void delete_list(ListNode* p);

void print_list(ListNode* p, const string & s = "");
void gen_list(int n, ListNode* p,bool sorted = false);

ListNode* mergeTwoLists(ListNode*  l1, ListNode* l2);
void test_mergeTwoLists(void);
void test_addTwoNumbers(void);
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

void test_swapPairs(void);
ListNode* swapPairs(ListNode* l);

ListNode* mergeKLists(vector<ListNode*> & lists);
void test_mergeKLists(void);

ListNode* removeElements(ListNode* head, int val);
void test_removeElements(void);

#endif

