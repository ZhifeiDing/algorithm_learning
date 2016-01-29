#include "leetcode.hpp"
/*
 *
 *Given a linked list and a value x, partition it such that all nodes less
 *than x come before nodes greater than or equal to x.
 *
 *You should preserve the original relative order of the nodes in each of the
 *two partitions.
 *
 *For example,
 *Given 1->4->3->2->5->2 and x = 3,
 *return 1->2->2->4->3->5.
 */

ListNode *partition(ListNode *head, int x) {
    ListNode dummyLess(-1);
    ListNode dummy(-1);

    ListNode *pLess = &dummyLess;
    ListNode *p = &dummy;

    while( head ) {
        if( head->val < x ) {
            pLess->next = head;
            pLess = pLess->next;
        } else {
            p->next = head;
            p = p->next;
        }
        head = head->next;
    }

    pLess->next = dummy.next;
    p->next = NULL;

    return dummyLess.next;
}
