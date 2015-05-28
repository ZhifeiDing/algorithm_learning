#include "leetcode.hpp"

/*
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: 
 * Starting with any positive integer, replace the number by the 
 * sum of the squares of its digits, and repeat the process until 
 * the number equals 1 (where it will stay), or it loops endlessly 
 * in a cycle which does not include 1. Those numbers for which 
 * this process ends in 1 are happy numbers.
 * 
 * Example: 19 is a happy number
 * 
 * 1^2 + 9^2 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 */
int sqrt_sum(int n) {
    int sum = 0;
    while(n) {
        int d = n%10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> dict;
    dict.insert(n);
    
    while(true) {
        int sum = sqrt_sum(n);
        if( sum == 1 )
            return true;
        else if( dict.find(sum) != dict.end() )
            return false;
        else {
            dict.insert(sum);
            n = sum;
        }
    }
    
}
