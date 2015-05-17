#include "leetcode.hpp"
/*
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 */

ListNode* removeElements(ListNode* head, int val) {

  ListNode dummy(-1);
  dummy.next = head;
  ListNode* pre = &dummy;
  while( head ) {
    if( head->val == val ) {
      pre->next = head->next;
    } else {
      pre = head;
    }
    head = head->next;
  }
  return dummy.next;
}
