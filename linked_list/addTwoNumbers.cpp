/*
 * Question:  You are given two linked lists representing two 
 * non-negative numbers. The digits are stored in reverse order 
 * and each of their nodes contains a single digit. Add the two 
 * numbers and return it as a linked list. 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) 
 * Output: 7 -> 0 -> 8 
 * Solution:  Keep track of the carry using a variable and simulate 
 * digits-by-digits sum from the head of list, which contains the 
 * least-significant digit. Take extra caution of the following 
 * cases: - When one list is longer than the other.  - The sum could 
 * have an extra carry of one at the end, which is easy to forget. 
 * (e.g., (9 -> 9) + (1) = (0 -> 0 -> 1)) 
 */
#include "leetcode.hpp"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int carry = 0;
  ListNode dummy(0,NULL);
  ListNode* p = &dummy;
  while( l1 && l2 ) {
    int n = l1->val + l2->val + carry;
    carry = 0;
    if( n <= 9 ) {
      p->next = new ListNode(n,NULL);
    } else {
      p->next = new ListNode(n%10,NULL);
      carry = 1;
    }
    l1 = l1->next;
    l2 = l2->next;
    p = p->next;
  }
  if( l2 ) l1 = l2;
  while( l1 ) {
    int n = l1->val + carry;
    carry = n / 10;
    p->next = new ListNode(n%10,NULL);;
    l1 = l1->next;
    p = p->next;
  }
  if( carry ) p->next = new ListNode(carry,NULL);

  return dummy.next;
}
