#include "leetcode.hpp"

void test_detectCycle() {

  srand((unsigned int)time(NULL));
  int n = rand()%11;
  ListNode dummy;
  gen_list(n, &dummy, true);
  print_list(dummy.next, "Original");
  ListNode *s = detectCycle(dummy.next);
  if( s == NULL )
    cout << "has nocycle" << endl;
  else
    cout << "cycle startpoint : " << s->val << endl;
  ListNode *tail = dummy.next;
  while( tail->next )
    tail = tail->next;
  tail->next = dummy.next;
  s = detectCycle(dummy.next);
  if( s == NULL )
    cout << "has nocycle" << endl;
  else
    cout << "cycle startpoint : " << s->val << endl;
}
