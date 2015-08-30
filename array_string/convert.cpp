#include "leetcode.hpp"

/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on 
 * a given number of rows like this: (you may want to display this 
 * pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given 
 * a number of rows:
 * 
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

string convert(string s, int numRows) {
    if( numRows == 1 )
        return s;
    string r;
    r.resize(s.size());
    int idx = 0;
    for(int i = 0; i < numRows; i++) {
        for(int j = i; j < s.size(); j += 2*numRows-2) {
            r[idx++] =  s[j];
            if( i != 0 && i != numRows-1 && j + 2* (numRows - i -1) < s.size())
                r[idx++] = s[j + 2* (numRows - i -1)];
        }
    }
    return r;
}
