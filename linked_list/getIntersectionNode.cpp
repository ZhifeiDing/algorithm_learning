#include "leetcode.hpp"

/*
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * 
 * 
 * For example, the following two linked lists:
 * 
 * A:          a1 → a2
 *                    ↘
 *                      c1 → c2 → c3
 *                    ↗            
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 * 
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  ListNode *a = headA, *b = headB;

  while( a != b ) {
    a = a ? a->next : headB;
    b = b ? b->next : headA;
  }
  return a;
}

// first get the length of two list then match them by the shorter list
int getLenOfList(ListNode *head) {
  if( head == NULL ) 
    return 0;
  return 1 + getLenOfList(head->next);
}

ListNode *getIntersectionNode_2nd(ListNode *headA, ListNode *headB) {

  int lenA = getLenOfList(headA);
  int lenB = getLenOfList(headB);

  ListNode *a = headA, *b = headB;
  for(int i = 0; i < lenA - lenB; ++i)
    a = a->next;
  for(int i = 0; i < lenB - lenA; ++i)
    b = b->next;

  while( a != b ) {
    a = a->next;
    b = b->next;
  }

  return a;
}
