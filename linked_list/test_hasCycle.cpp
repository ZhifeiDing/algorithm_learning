#include "leetcode.hpp"

void test_hasCycle() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  ListNode dummy;
  gen_list(n, &dummy, true);
  print_list(dummy.next, "Original");
  string s = hasCycle(dummy.next) ? "has cycle " : "has no cycle";
  cout << s << endl;
  ListNode *tail = dummy.next;
  while( tail->next )
    tail = tail->next;
  tail->next = dummy.next;
  s = hasCycle(dummy.next) ? "has cycle " : "has no cycle";
  cout << s << endl;
}
