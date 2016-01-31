#include "leetcode.hpp"

/*
 *
 *
 *Given a singly linked list, group all odd nodes together followed by the
 *even nodes. Please note here we are talking about the node number and not the
 *value in the nodes.
 *
 *You should try to do it in place. The program should run in O(1) space
 *complexity and O(nodes) time complexity.
 *
 *Example:
 *Given 1->2->3->4->5->NULL,
 *return 1->3->5->2->4->NULL.
 *
 *Note:
 *The relative order inside both the even and odd groups should remain as it
 *was in the input.
 *The first node is considered odd, the second node even and so on ...
 */

ListNode *oddEvenList(ListNode *head) {
    if( head == NULL || head->next == NULL )
        return head;
    ListNode *p = head->next;
    ListNode even(-1);
    even.next = p;
    ListNode *odd = head;

    while( odd && p && p->next ) {
        if( odd->next->next )
            odd->next = odd->next->next;
        if( p->next->next )
            p->next = p->next->next;
        else
            p->next = NULL;
        p = p->next;
        odd = odd->next;
    }
    odd->next = even.next;

    return head;
}