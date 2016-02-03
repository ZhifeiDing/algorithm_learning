#include "leetcode.hpp"
/*
 *
 *Given a sorted linked list, delete all nodes that have duplicate numbers,
 *leaving only distinct numbers from the original list.
 *
 *For example,
 *Given 1->2->3->3->4->4->5, return 1->2->5.
 *Given 1->1->1->2->3, return 2->3.
 */

ListNode* deleteDuplicatesII(ListNode* head) {
    unordered_map<int,int> valCnt;
    ListNode* r = head;
    while( r ) {
        ++valCnt[r->val];
        r = r->next;
    }
    ListNode dummy(-1);
    r = &dummy;
    while( head ) {
        if( valCnt[head->val] == 1 ) {
            r->next = head;
            r = r->next;
        }
        head = head->next;
    }
    r->next = NULL;
    return dummy.next;
}
