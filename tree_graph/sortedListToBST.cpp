#include "leetcode.hpp"

/*
 * Given a singly linked list where elements are sorted in 
 * ascending order, convert it to a height balanced BST.
 */


TreeNode* sortedListToBSTHelper(ListNode* head, ListNode* pre) {
      if( head == pre )
          return NULL;
      
      ListNode *slow = head, *fast = head;
      while( fast != pre && fast->next != pre ) {
        fast = fast->next->next;
        slow = slow->next;
      }
      
      TreeNode* root = new TreeNode(slow->val);
      root->left = sortedListToBSTHelper(head, slow);
      root->right = sortedListToBSTHelper(slow->next, pre);
      return root;
}

TreeNode* sortedListToBST(ListNode* head) {
      return sortedListToBSTHelper(head, NULL);
}
