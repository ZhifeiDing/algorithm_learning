#include "leetcode.hpp"
#include "Queue.cpp"

void test_Queue() {
  Queue q;
  srand((unsigned int)time(NULL));
  int n = rand()%17;
  int i = 0;
  while( i++ < n ) {
    int x = rand()%20;
    q.push(x);
    cout << x << " ";
  }
  cout << endl;
  while( !q.empty() ) {
    cout << q.peek() << " ";
    q.pop();
  }
  cout << endl;
}
