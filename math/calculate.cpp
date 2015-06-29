#include "leetcode.hpp"

/*
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), 
 * the plus + or minus sign -, non-negative integers and empty spaces .
 * 
 * You may assume that the given expression is always valid.
 * 
 * Some examples:
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 * Note: Do not use the eval built-in library function.
 */

int calculate(string s) {
    int r = 0;
    vector<int> v;
    int preSign = 1, localSign = 1;
    
    for(int i = 0; i < s.size(); i++) {
        switch(s[i]) {
            case ' ':
            case '+':
            break;
            case '-':
            localSign = -1;
            break;
            case '(':
            preSign *= localSign;
            v.push_back(localSign);
            localSign = 1;
            break;
            case ')':
            preSign *= v.back();
            v.pop_back();
            localSign = 1;
            break;
            default:
            int x = 0;
            while(s[i] >= '0' && s[i] <= '9')
                x = x*10 + ( s[i++] - '0' );
            r += x * localSign * preSign;
            localSign = 1;
            i--;
        }
    }
    return r;
}
