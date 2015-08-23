#include "leetcode.hpp"

/*
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You must do this in-place without altering the nodes' values.
 * 
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */
void reorderList(ListNode* head) {
  ListNode *tail = head, *mid = head;
  if( !head )
    return;
  while( tail && tail->next ) {
    mid = mid->next;
    tail = tail->next->next;
  }
  tail = mid->next;
  mid->next = NULL;
  mid = NULL;
  while( tail ) {
    ListNode *t = tail->next;
    tail->next = mid;
    mid = tail;
    tail = t;
  }
  tail = mid;
  while( head && tail ) {
    ListNode *node1 = head->next;
    ListNode *node2 = tail->next;
    head->next = tail;
    tail->next = node1;
    head = node1;
    tail = node2;
  }
}
