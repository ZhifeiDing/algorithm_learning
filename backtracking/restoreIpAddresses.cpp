#include "leetcode.hpp"

/*
 * Given a string containing only digits, restore it by returning all possible valid IP 
 * address combinations.
 * 
 * For example:
 * Given "25525511135",
 * 
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

void restoreIpAddressesHelper(string & s, vector<string> & r, string ip, int start, int n) {
    if( start == s.size() && n == 0 ) {
        ip.pop_back();
        r.push_back(ip);
        return;
    }
    for(int i = start, count = 0; i < s.size() && 0 < n; i++) {
        count = count * 10 + s[i] - '0';
        if( count < 256 ) {
            restoreIpAddressesHelper(s, r, ip + to_string(count) + ".", i + 1, n-1);
        }
        if( count == 0 )
            return;
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> r;
    if( 12 < s.size() )
        return r;
    string ip;
    restoreIpAddressesHelper(s, r, ip, 0, 4);
    return r;
}
