/*
 * Question:   Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first 
 * two lists. 
 * Solution:  We insert a dummy head before the new list so we don’t have 
 * to deal with special cases such as initializing the new list’s head. Then 
 * the new list’s head could just easily be returned as dummy head’s next node.  
 * Using dummy head allows you to write simpler code and adds as a powerful 
 * tool to your interview arsenal
 */
#include "leetcode.hpp"

ListNode* mergeTwoLists(ListNode*  l1, ListNode* l2) {
  ListNode dummy(0);
  ListNode* p = &dummy;
  while( l1 != NULL && l2 != NULL ) {
    if( l1->val < l2->val ) {
      p->next = l1;
      l1 = l1->next;
    } else {
      p->next = l2;
      l2 = l2->next;
    }
    p = p->next;
  }
  if( l1 != NULL ) p->next = l1;
  if( l2 != NULL ) p->next = l2;
  return dummy.next;
}
