#include "leetcode.hpp"
/*
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 */

ListNode* half;

bool isPalindrome(ListNode* slow, ListNode* fast) {
  if (fast == nullptr) {
    half = slow;
    return true;
  }
  if (fast->next == nullptr) {
    half = slow->next;
    return true;
  }

  if (isPalindrome(slow->next, fast->next->next) && slow->val == half->val) {
    half = half->next;
    return true;
  }

  return false;
}

bool isPalindrome(ListNode* head) {
  return isPalindrome(head, head);
}
