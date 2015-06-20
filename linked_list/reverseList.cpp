#include "leetcode.hpp"
/*
 * Reverse a singly linked list.
 * 
 * click to show more hints.
 * 
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

ListNode* reverseList(ListNode* head) {
    ListNode *pre = NULL, *cur = head;
    while( cur ) {
        head = cur->next;
        cur->next = pre;
        pre = cur;
        cur = head;
    }
    return pre;
}
ListNode* r = NULL;
void reverseList_recursiveHelper(ListNode* head, ListNode* pre) {
  if( !head->next ) {
    head->next = pre;
    r = head;
  } else {
    reverseList_recursiveHelper(head->next, head);
    head->next = pre;
  }
}
ListNode* reverseList_recursive(ListNode* head) {
  if( !head ) return NULL;
  reverseList_recursiveHelper(head, NULL);
  return r;
}
