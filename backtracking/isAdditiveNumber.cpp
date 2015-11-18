#include "leetcode.hpp"

/*
 * Additive number is a positive integer whose digits can form additive sequence.
 * 
 * A valid additive sequence should contain at least three numbers. Except for the 
 * first two numbers, each subsequent number in the sequence must be the sum of the 
 * preceding two.
 * 
 * For example:
 * "112358" is an additive number because the digits can form an additive 
 * sequence: 1, 1, 2, 3, 5, 8.
 * 
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
 * 1 + 99 = 100, 99 + 100 = 199
 * Note: Numbers in the additive sequence cannot have leading zeros, so sequence 
 * 1, 2, 03 or 1, 02, 3 is invalid.
 * 
 * Given a string represents an integer, write a function to determine if it's an 
 * additive number.
 * 
 * Follow up:
 * How would you handle overflow for very large input integers?
 */


string stringAdd(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string r;
    int add = 0, i;
    for(i = 0; i < min(num1.size(), num2.size()); ++i) {
        int acc = num1[i] - '0' + num2[i] - '0' + add;
        r.push_back(acc % 10 + '0');
        add = acc / 10;
    }
    if( num1.size() < num2.size() )
        num1 = num2;
    for(; i < num1.size(); ++i) {
        int acc = num1[i] - '0' + add;
        r.push_back(acc % 10 + '0');
        add = acc / 10;
    }
    if( add )
        r.push_back(add);
    return r;
}

bool isAdditiveNumberHelper(string num1, string num) {
    int i = num1.size();
    for(int j = 1; j < num.size() - i; ++j) {
            string num2 = num.substr(0, j);
            if( num2.size() > 1 && num2[0] == '0' )
                break;
            string res = stringAdd(num1, num2);
            if( res.size() + j > num.size() )
                break;
            if( res == num.substr(j, res.size()) )
                if( res.size() + j == num.size() )
                    return true;
                else
                    if( isAdditiveNumberHelper(res, num.substr(j + res.size())) )
                        return true;
    }
    return false;
}

bool isAdditiveNumber(string num) {

    for(int i = 1; i < num.size() / 2; ++i) {
        string num1 = num.substr(0,i);
        if( num1.size() > 1 && num1[0] == '0' )
            break;
        if( isAdditiveNumberHelper(num1, num.substr(i)) )
            return true;
    }
    return false;
}
