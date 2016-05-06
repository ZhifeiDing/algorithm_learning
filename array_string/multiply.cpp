#include "leetcode.hpp"
/*
 *
 *Given two numbers represented as strings, return multiplication of the
 *numbers as a string.
 *
 *Note:
 *The numbers can be arbitrarily large and are non-negative.
 *Converting the input string to integer is NOT allowed.
 *You should NOT use internal library such as BigInteger.
 */
string multiply(string num1, string num2) {
    if( num1.size() < num2.size() )
        return multiply(num2,num1);
    string r(num1.size()+num2.size(),'0');
    for(int i = num2.size()-1; i >= 0; --i) {
        int carry = 0;
        int j;
        for(j = num1.size()-1; j >= 0; --j) {
            int val = ( r[i+j+1] - '0' ) + ( num1[j] - '0' ) * ( num2[i] - '0' ) + carry;
            carry = val/10;
            r[i+j+1] = val%10 + '0';
        }
        r[i] = carry + '0';
    }
    int i = 0;
    while( i < r.size()-1 && r[i] == '0' )
        ++i;
    return r.substr(i);
}
