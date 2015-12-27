#include "leetcode.hpp"

/*
 * Given a singly linked list where elements are sorted in 
 * ascending order, convert it to a height balanced BST.
 */

// top - bottom solution : O(nlogn)

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

// bottom - up solution  : O(n)
TreeNode* sortedListToBSTHelperI(ListNode* &head, int start, int end) {
    if( start > end )
        return NULL;
        
    int idx = start + ceil(float( end - start )/2);
    
    TreeNode *left = sortedListToBSTHelperI(head, start, idx-1);
    TreeNode *root = new TreeNode(head->val);
    root->left = left;
    head = head->next;
    root->right = sortedListToBSTHelperI(head, idx+1, end);
    
    return root;
}

TreeNode* sortedListToBST_n(ListNode* head) {
      int len = 0;
      ListNode *node = head;
      while( node != NULL ) {
          node = node->next;
          ++len;
      }
      return sortedListToBSTHelperI(head, 0, len-1);
}
