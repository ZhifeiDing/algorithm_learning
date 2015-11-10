#include "leetcode.hpp"

/*
 * Divide two integers without using multiplication, division and mod operator.
 * 
 * If it is overflow, return MAX_INT.
 */

int divide(int dividend, int divisor) {
    if( dividend == 0 )
        return 0;
    if( dividend == INT_MIN )
        if( divisor == 1 )
            return INT_MIN;
        else if( divisor == -1 )
            return INT_MAX;
    
    bool neg = ( dividend < 0 ) ^ ( divisor < 0 );
    int r = 0;
    dividend = dividend < 0 ? dividend : -1 * dividend;
    divisor = divisor < 0 ? divisor : -1 * divisor;
    
    while( divisor >= dividend ) {
        ++r;
        dividend -= divisor;
    }
    return neg ? -1 * r : r;
}

int divide_bs(int dividend, int divisor) {
    if( divisor == 0 )
        return INT_MAX;
    if( dividend == 0 )
        return 0;
    if( divisor == 1 )
        return dividend;
    if( divisor == -1 )
        if( dividend == INT_MIN )
            return INT_MAX;
        else
            return -1 * dividend;
            
    bool neg = ( dividend > 0 ) ^ ( divisor > 0 ) ;
    int r = 0;
    dividend = dividend < 0 ? dividend : -1 * dividend;
    divisor = divisor < 0 ? divisor : -1 * divisor;
    
    cout << "dividend = " << dividend << " , divisor = " << divisor << endl;
    int d = divisor;
    while( d >= dividend ) {
        ++r;
        d = d << 1;
    }
    if( r == 0 )
        return 0;
        
    d = d >> 1;
    
    return neg ? -1 * ( pow(2,r-1) + divide(dividend - d, divisor) ) : pow(2,r-1) + divide(dividend - d, divisor);
}
