#include "leetcode.hpp"

/*
 * Design a stack that supports push, pop, top, and retrieving the 
 * minimum element in constant time.
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */

class MinStack {
public:
    void push(int x) {
        st.push(x);
        if( minSt.empty() )
            minSt.push(x);
        else if( x <= minSt.top() ) 
            minSt.push(x);
    }

    void pop() {
        if( st.top() == minSt.top() )
            minSt.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
private:
    stack<int> st;
    stack<int> minSt;
};
