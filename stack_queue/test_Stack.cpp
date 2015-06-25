#include "leetcode.hpp"
#include "Stack.cpp"

void test_Stack() {
  Stack s;
  srand((unsigned int)time(NULL));
  int n = rand()%9;
  while( n-- ) {
    s.push(rand()%9);
    cout << s.top() << " ";
  }
  cout << endl;
  while( !s.empty() ) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}
