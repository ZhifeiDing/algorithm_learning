#include "leetcode.hpp"

void test_rotateRight() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  int k = rand()%(n+1);
  ListNode dummy;
  gen_list(n, &dummy, true);
  print_list(dummy.next, "Original");

  ListNode *r = rotateRight(dummy.next, k);
  cout << "k = " << k << endl;
  print_list(r, "Rotate");
}
