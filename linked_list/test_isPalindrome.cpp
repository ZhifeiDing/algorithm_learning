#include "leetcode.hpp"

void test_isPalindrome() {
  // generate two list
  vector<int> a1;
  srand((unsigned int)time(NULL));
  int n1 = rand() % 5;
  gen_array(n1,a1,10);
  cout << "List1 : ";
  print_array(a1);
  ListNode l1(0,NULL);
  ListNode* p1 = &l1; 
  for(int i = 0; i < n1;i++) {
     p1->next = new ListNode(a1[i],NULL);
     p1 = p1->next;
  }
  isPalindrome(l1.next) ? cout << "Palindrome\n" : cout << "Not Palindrome\n";
}
