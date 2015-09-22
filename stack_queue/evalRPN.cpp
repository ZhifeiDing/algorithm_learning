#include "leetcode.hpp"

/*
 * Evaluate the value of an arithmetic expression in Reverse 
 * Polish Notation.
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or 
 * another expression.
 * 
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

int evalRPN(vector<string>& tokens) {
    stack<int> s;
    int i = 0;
    while( i < tokens.size() ) {
        if( tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ) {
          char c = tokens[i][0];
          int l, r;
        switch(c) {
            case '+' :
                r = s.top();s.pop();
                l = s.top();s.pop();
                s.push(r+l);
                break;
            case '-' :
                r = s.top();s.pop();
                l = s.top();s.pop();
                s.push(l-r);
                break;
            case '*' :
                r = s.top();s.pop();
                l = s.top();s.pop();
                s.push(l*r);
                break;
            case '/' :
                r = s.top();s.pop();
                l = s.top();s.pop();
                s.push(l/r);
                break;
            default :
                break;
        }
        } else {
        s.push(stoi(tokens[i]));
        }
        ++i;
    }
    return s.empty() ? 0 : s.top();
}
