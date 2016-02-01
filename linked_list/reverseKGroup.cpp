#include "leetcode.hpp"
/*
 *
 *Given a linked list, reverse the nodes of a linked list k at a time and
 return its modified list.
 *
 *If the number of nodes is not a multiple of k then left-out nodes in the
 end should remain as it is.
 *
 *You may not alter the values in the nodes, only nodes itself may be changed.
 *
 *Only constant memory is allowed.
 *
 *For example,
 *Given this linked list: 1->2->3->4->5
 *
 *For k = 2, you should return: 2->1->4->3->5
 *
 *For k = 3, you should return: 3->2->1->4->5
 */
ListNode* reverse(ListNode *head) {
    ListNode *pre = NULL, *cur = head;
    while( cur ) {
        head = cur->next;
        cur->next = pre;
        pre = cur;
        cur = head;
    }
    return pre;
}

ListNode* reverseKGroup(ListNode *head, int k) {
    int idx = 0;
    ListNode dummy(-1);
    ListNode *r = &dummy;
    ListNode *nextHead = head;
    while( nextHead ) {
        ++idx;
        if( idx == k ) {
            ListNode *t = nextHead->next;
            nextHead->next = NULL;
            r->next = reverse(head);
            r = head;
            idx = 0;
            nextHead = t;
            head = nextHead;
        } else {
            nextHead = nextHead->next;
        }
    }
    if( idx )
        r->next = head;
    return dummy.next;
}
