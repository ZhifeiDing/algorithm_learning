#include "leetcode.hpp"
/*
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * 
 * The digits are stored such that the most significant digit is at the head of the list.
 */

vector<int> plusOne(vector<int>& digits) {
    if( digits.size() == 0 )
        return digits;
    vector<int> r(digits.size()+1);
    int next = 1;
    for(int i = digits.size() - 1; 0 <= i; --i) {
        int val = digits[i] + next;
        next = val / 10;
        r[i+1] = val % 10;
    }
    if( next ) {
        r[0] = next;
        return r;
    } else {
        return vector<int>(r[1], r[digits.size()]);
    }
}
