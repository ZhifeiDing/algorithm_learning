#include "leetcode.hpp"
/*
 *
 *A message containing letters from A-Z is being encoded to numbers using the
 *following mapping:
 *
 *'A' -> 1
 *'B' -> 2
 *...
 *'Z' -> 26
 *Given an encoded message containing digits, determine the total number of
 *ways to decode it.
 *
 *For example,
 *Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 *The number of ways decoding "12" is 2.
 */
int numDecodings(string s) {
    // if the first num is '0' then no decoding is available
    if( s.size() == 0 || s[0] == '0' )
        return 0;
    int num = 1, preNum = 1;
    int idx = 1;
    while( idx < s.size() ) {
        if( s[idx] == '0' )
            num = 0;
        bool ableDecode = s[idx-1] == '1' || ( s[idx-1] == '2' && s[idx] < '7' );
        num += ableDecode ? preNum : 0;
        preNum = ableDecode ? num - preNum : num;
        ++idx;
    }
    return num;
}