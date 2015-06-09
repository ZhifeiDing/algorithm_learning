#include "leetcode.hpp"

/*
 * Given a sorted linked list, delete all duplicates such that each 
 * element appear only once.
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* r = head;
    while( head && head->next ) {
        if( head->val == head->next->val ) {
            head->next = head->next->next;
            continue;
        }
        head = head->next;
    }
    return r;
}
