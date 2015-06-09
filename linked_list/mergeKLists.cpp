#include "leetcode.hpp"

/*
 * Merge k sorted linked lists and return it as one sorted list. 
 * Analyze and describe its complexity.
 */

ListNode *merge(vector<ListNode *> &lists,int left,int right){
    if(left > right)return NULL;
    if(left == right)return lists[left];
    int mid = (left + right)/2;
    ListNode *first = merge(lists,left,mid);
    ListNode *second = merge(lists,mid + 1,right);

    if(first == NULL)return second;
    if(second == NULL)return first;

    ListNode *head = NULL;
    ListNode *ptr = NULL;
    ListNode *pre = NULL;

    while(first && second){
        if(first->val < second->val){
            ptr = first;
            first = first->next;
        }else{
            ptr = second;
            second = second->next;
        }
        if(NULL == head){
            head = ptr;
            pre = ptr;
            continue;
        }
        pre->next = ptr;
        pre = ptr;
    }
    if(first)pre->next = first;
    if(second)pre->next = second;
    return head;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    return merge(lists,0,lists.size() -1);
}

/*
 * use max heap to merge K lists
 */
class mycomparison {
public:
  bool operator() (ListNode* i, ListNode* j) {
    return i->val < j->val;
  }
};
ListNode *mergeKLists_heap(vector<ListNode *> &lists) {
  priority_queue<ListNode*, vector<ListNode*>, mycomparison> minHeap;
  ListNode dummy(-1);
  ListNode* cur = &dummy;
  for(int i = 0; i < lists.size(); i++)
    if( lists[i] != NULL ) 
      minHeap.push(lists[i]);
  while( !minHeap.empty() ) {
    cur->next = minHeap.top();
    minHeap.pop();
    cur = cur->next;
    if( cur->next != NULL && !minHeap.empty() )
      minHeap.push(cur->next);
  }
  return dummy.next;
}
