#include "leetcode.hpp"


void test_mergeTwoLists(void) {
  vector<int> a1,a2;
  srand((unsigned int)time(NULL));
  int n1 = rand() % 5;
  int n2 = rand() % 7;
  gen_array(n1+n2,a1,10);
  a2.resize(n2);
  copy(a1.begin()+n1,a1.end(),a2.begin());
  a1.resize(n1);
  sort(a1.begin(),a1.end());
  sort(a2.begin(),a2.end());
  cout << "List1 : ";
  print_array(a1);
  cout << "List2 : ";
  print_array(a2);
  ListNode l1(0,NULL);
  ListNode l2(0,NULL);
  ListNode* p1 = &l1; 
  ListNode* p2 = &l2;
  for(int i = 0; i < n1;i++) {
     p1->next = new ListNode(a1[i],NULL);
     p1 = p1->next;
  }
  for(int i = 0; i < n2;i++) {
     p2->next = new ListNode(a2[i],NULL);
     p2 = p2->next;
  }
  p1 = l1.next;
  p2 = l2.next;
  print_list(p1);
  print_list(p2);
  ListNode* r = mergeTwoLists(l1.next,l2.next);
  print_list(r);
}
