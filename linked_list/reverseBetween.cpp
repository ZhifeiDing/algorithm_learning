#include "leetcode.hpp"
/*
 * Reverse a linked list from position m to n. Do it in-place 
 * and in one-pass.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * 
 * return 1->4->3->2->5->NULL.
 * 
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 */


ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode dummy(-1);
    dummy.next = head;
    ListNode* pre = &dummy, *prem;
    for(int i = 1; i <= n; i++) {
        
        ListNode* t = head->next;
        
        if( i == m ) {
            prem = pre;
        } else if( i > m ) {
            head->next = pre;
        }
        pre = head;
        head = t;
    }
    prem->next->next = head;
    prem->next = pre;
    
    return dummy.next;
}
