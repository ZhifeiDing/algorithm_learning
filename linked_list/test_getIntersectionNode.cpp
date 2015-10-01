#include "leetcode.hpp"

void test_getIntersectionNode() {
  srand((unsigned int)time(NULL));
  int n = rand()%10+1;
  ListNode dummy(-1);
  gen_list(n, &dummy);
  ListNode *headA = dummy.next;
  ListNode *headB = headA->next;
  print_list(headA);
  print_list(headB);
  cout << "intersection node = " << getIntersectionNode(headA, headB)->val << endl;
}
