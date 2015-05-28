#include "leetcode.hpp"

void test_reverseBetween(void) {
  srand((unsigned int)time(NULL));
  int len = rand()%15;
  int m, n;
  do {
    m = rand()%len;
    n = rand()%len;
  } while( m > n );
  ListNode* head;
  gen_list(len, head);
  print_list(head, "Original");
  ListNode* r = reverseBetween(head, m, n);
  cout << "m = " << m << " n = " << n << endl;
  print_list(r, "Reverse");
} 
