#include "leetcode.hpp"

/*
 * Given an integer n, count the total number of digit 1 appearing in 
 * all non-negative integers less than or equal to n.
 * 
 * For example:
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 
 * 1, 10, 11, 12, 13.
 */ 
int countDigitOne(int n) {
    unsigned int r = 0;
    for(long long int i = 1; i <= n; i *= 10) {
        int a = n/i, b = n%i;
        r += ( a + 8 ) / 10 * i + ( a%10 == 1 ) * ( b + 1 );
    }
    return r;
}
