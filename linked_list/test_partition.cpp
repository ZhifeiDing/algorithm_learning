#include "leetcode.hpp"

void test_partition() {

  srand((unsigned int)time(NULL));
  int n = rand()%11;
  ListNode dummy;
  //gen_list(n, &dummy, true);
  gen_list(n, &dummy);
  print_list(dummy.next, "Original");
  int x = rand()%n;
  ListNode *r = partition(dummy.next, x);
  cout << "x = " << x << endl;
  print_list(r, "Partition");
}
