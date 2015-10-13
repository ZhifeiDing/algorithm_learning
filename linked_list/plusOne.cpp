#include "leetcode.hpp"
/*
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * 
 * The digits are stored such that the most significant digit is at the head of the list.
 */

vector<int> plusOne(vector<int>& digits) {
    if( digits.size() == 0 )
        return digits;
    vector<int> r(digits);
    int next = 1;
    for(int i = digits.size() - 1; 0 <= i; --i) {
      if( r[i] < 9 ) {
        ++r[i];
        break;
      }
      r[i] = 0;
    }
    if( r[0] == 0 )
      r.insert(r.begin(),1);
    return r;
}
