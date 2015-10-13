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

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


RandomListNode *copyRandomList(RandomListNode *head);
void test_copyRandomList(void);

void delete_list(ListNode* p);

void print_list(ListNode* p, const string & s = "");
void gen_list(int n, ListNode* p,bool sorted = false);

ListNode* mergeTwoLists(ListNode*  l1, ListNode* l2);
void test_mergeTwoLists(void);
void test_addTwoNumbers(void);
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

ListNode* reverseList_recursive(ListNode* head);
ListNode* reverseList(ListNode* head);
void test_reverseList();

bool isPalindrome(ListNode* head);
void test_isPalindrome();

void deleteNode(ListNode* node);
void test_deleteNode();

ListNode *mergeKLists(vector<ListNode *> &lists);
ListNode *mergeKLists_heap(vector<ListNode *> &lists);
void test_mergeKLists();

void test_swapPairs(void);
ListNode* swapPairs(ListNode* l);

ListNode* mergeKLists(vector<ListNode*> & lists);
void test_mergeKLists(void);

ListNode* removeElements(ListNode* head, int val);
void test_removeElements(void);

ListNode* reverseBetween(ListNode* head, int m, int n);
void test_reverseBetween(void);

ListNode* deleteDuplicates(ListNode* head);
void test_deleteDuplicates();

bool hasCycle(ListNode *head);
void test_hasCycle();

void reorderList(ListNode* head);
void test_reorderList();

ListNode *detectCycle(ListNode *head);
void test_detectCycle();

int findDuplicate(vector<int> & nums);
void test_findDuplicate();
int findDuplicate_bs(vector<int> & nums);
int findDuplicate_bit(vector<int> & nums);

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
void test_getIntersectionNode();
ListNode *getIntersectionNode_2nd(ListNode *headA, ListNode *headB);

vector<int> plusOne(vector<int>& digits);
void test_plusOne();

string addBinary(string a, string b);
void test_addBinary();
#endif

