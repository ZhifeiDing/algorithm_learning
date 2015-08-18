#include "leetcode.hpp"

/*
 * Given a linked list, determine if it has a cycle in it.
 * 
 * Follow up:
 * Can you solve it without using extra space?
 */
bool hasCycle(ListNode *head) {
  if( head == NULL )
    return false;
  ListNode *mid = head, *tail = head->next;
  while( tail != NULL && tail->next != NULL && mid != tail ) {
    mid = mid->next;
    tail = tail->next->next;
  }
  return mid == tail;
}
