#include "leetcode.hpp"
/*
 * Follow up for H-Index: What if the citations array is sorted in 
 * ascending order? Could you optimize your algorithm?
 * 
 * Hint:
 * 
 * Expected runtime complexity is in O(log n) and the input is sorted.
 */

int hIndexII(vector<int>& citations) {
    int l = 0, r = citations.size()-1;
    while( l <= r ) {
        int m = ( r + l ) / 2;
        if( citations[m] < citations.size() - m )
            l = m + 1;
        else if( citations.size() - m < citations[m] )
            r = m - 1;
        else
            return citations.size() - m;
    }
    return citations.size() - l;
}
