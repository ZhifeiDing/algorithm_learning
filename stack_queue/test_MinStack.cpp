#include "leetcode.hpp"
#include "MinStack.cpp"

void test_MinStack() {
  MinStack st;
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  for(int i = 0; i < n; i++) {
    st.push(rand()%99);
    cout << "st.top = " << st.top() << "; st.min = " << st.getMin() << endl;  
  }
  for(int i = 1; i < n; i++) {
    st.pop();
    cout << "after pop st.min = " << st.getMin() << endl;
  }
}
