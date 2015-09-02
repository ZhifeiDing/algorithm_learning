#include "leetcode.hpp"

/*
 * Convert a non-negative integer to its english words 
 * representation. Given input is guaranteed to be less than 231 - 1.
 * 
 * For example,
 * 123 -> "One Hundred Twenty Three"
 * 12345 -> "Twelve Thousand Three Hundred Forty Five"
 * 1234567 -> "One Million Two Hundred Thirty Four Thousand Five 
 * Hundred Sixty Seven"
 * Hint:
 * 
 * Did you see a pattern in dividing the number into chunk of words? 
 * For example, 123 and 123000.
 * Group the number by thousands (3 digits). You can write a helper 
 * function that takes a number less than 1000 and convert just 
 * that chunk to words.
 * There are many edge cases. What are some good test cases? Does your 
 * code work with input such as 0? Or 1000010? (middle chunk is zero 
 * and should not be printed out)
 */

const vector<string> numMapThou = {"Thousand", "Million", "Billion", "Trillion"};
const vector<string> numMapLess = {"One","Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten","Eleven", 
"Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const vector<string> numMapMore = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

string convertHundred(int num) {
    string s;
    int n1 = num%10;
    num = num/10;
    int n2 = num%10;
    num = num/10;
    int n3 = num%10;
    if( n3 ) {
        s.append(numMapLess[n3-1]);
        s.append(" Hundred");
        if( n2 || n1 )
            s.append(" ");
    }
    if( n2 == 0 && n1 ) {
        s.append(numMapLess[n1-1]);
    } else if( n2 == 1 ) {
        s.append(numMapLess[10 + n1 -1]);
    } else if( n2 ) {
        s.append(numMapMore[n2]);
        if( n1 ) {
            s.append(" ");
            s.append(numMapLess[n1-1]);
        }
    }
    return s;
}


string numberToWords(int num) {
    string s;
    int idx = 0;
    if( num == 0 )
        return "Zero";
    while( num ) {
        if( idx && num%1000 ) {
            if( !s.empty() )
                s.insert(0," ");
            s.insert(0,numMapThou[idx-1]);
            s.insert(0," ");
        }
        s.insert(0,convertHundred(num%1000));
        idx++;
        num /= 1000;
    }
    return s;
}
