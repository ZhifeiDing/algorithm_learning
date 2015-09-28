#include "leetcode.hpp"
/*
 * Given a string that contains only digits 0-9 and a target value, 
 * return all possibilities to add binary operators (not unary) 
 * +, -, or * between the digits so they evaluate to the target value.
 * 
 * Examples: 
 * "123", 6 -> ["1+2+3", "1*2*3"] 
 * "232", 8 -> ["2*3+2", "2+3*2"]
 * "105", 5 -> ["1*0+5","10-5"]
 * "00", 0 -> ["0+0", "0-0", "0*0"]
 * "3456237490", 9191 -> []
 */

void addOperatorsHelper(string & num, int & target, int start, long long int presum, long long int last, string s, vector<string> & r) {
    if( start == num.size() && target == int(presum + last) ) {
        r.push_back(s);
        return;
    }
    long long int sum = 0;
    int len = num[start] == '0' ? start + 1 : num.size();
    for(int i = start; i < len; i++) {
        sum = sum * 10 + num[i] - '0';
        
        addOperatorsHelper(num, target, i + 1, presum + last, sum, s + "+" + num.substr(start,i - start + 1), r);
        addOperatorsHelper(num, target, i + 1, presum + last, -sum, s + "-" + num.substr(start,i - start + 1), r);
        addOperatorsHelper(num, target, i + 1, presum, last * sum, s + "*" + num.substr(start,i - start + 1), r);
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> r;
    string s;
    long long int pre = 0;
    if( num.size() == 0 )
      return r;
    int len = num[0] == '0' ? 1 : num.size();
    for(int i = 0; i < num.size(); i++) {
        s = num.substr(0,i+1);
        pre = pre * 10 + num[i] - '0';
        addOperatorsHelper(num, target, i+1, 0, pre, s, r);
    }
    return r;
}
