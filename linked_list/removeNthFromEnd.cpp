#include "leetcode.hpp"
/*
 *
 *Given a linked list, remove the nth node from the end of list and return its head.
 *
 *For example,
 *
 *   Given linked list: 1->2->3->4->5, and n = 2.
 *
 *   After removing the second node from the end, the linked list becomes 1->2->3->5.
 *Note:
 *Given n will always be valid.
 *Try to do this in one pass.
 */
ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *node = head;

    while( n-- > 0 && node )
        node = node->next;
    if( node == NULL )
        return head->next;
    ListNode *nthNode = head;
    node = node->next;
    while( node ) {
        node = node->next;
        nthNode = nthNode->next;
    }
    nthNode->next = nthNode->next->next;
    return head;
}
