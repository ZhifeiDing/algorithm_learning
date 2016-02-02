#include "leetcode.hpp"
/*
 *
 *Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 *For example:
 *Given 1->2->3->4->5->NULL and k = 2,
 *return 4->5->1->2->3->NULL.
 */

ListNode* rotateRight(ListNode *head, int k) {
    if( head == NULL )
        return head;
    int len = 0;
    ListNode *node = head;
    while( node->next ) {
        node = node->next;
        ++len;
    }
    k = k % ( len + 1 );
    if( k == 0 )
        return head;
    ListNode *last = node;
    node = head;
    while( k < len ) {
        node = node->next;
        --len;
    }
    last->next = head;
    head = node->next;
    node->next = NULL;
    return head;;
}
