#include "leetcode.hpp"

/*
 * Given a linked list, return the node where the cycle begins. 
 * If there is no cycle, return null.
 * 
 * Follow up:
 * Can you solve it without using extra space?
 */
ListNode *detectCycle(ListNode *head) {
  if( head == NULL )
    return NULL;
  ListNode *mid = head, *tail = head->next;
  while( tail != NULL && tail->next != NULL && mid != tail ) {
    mid = mid->next;
    tail = tail->next->next;
  }
  if( mid != tail )
    return NULL;
  mid = mid->next;
  while( mid != head ) {
    mid = mid->next;
    head = head->next;
  }
  return head;
}
