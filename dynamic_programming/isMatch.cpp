#include "leetcode.hpp"

/*
 * Implement regular expression matching with support for '.' and '*'.
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 */

bool isMatch(string s, string p) {
    int sSize = s.size(), pSize = p.size(), i, j;
    bool checked[sSize+1][pSize+1];
      fill_n(&matched[0][0], (sSize+1)*(pSize+1), false);

    for(j=2, checked[0][0]=true, checked[0][1]= false; j<=pSize; ++j) // match s[0..0]
        checked[0][j] = p[j-1] == '*'? checked[0][j-2]  : false;
    for(i=1; i<=sSize; ++i)
    for(j=1, checked[i][0]=false; j<=pSize; ++j)
    {
        if(p[j-1]=='*') // case (1)
            checked[i][j] = (j>1) && ( checked[i][j-2]  || ( ( checked[i-1][j-1] || checked[i-1][j]) && (s[i-1]== p[j-2] || p[j-2] == '.')) );
        else // case (2)
            checked[i][j] = checked[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');        
    }
    return checked[sSize][pSize];
}

bool helper(const string &s, const string &p, int sS, int pS)
{
    int sSize = s.size(), pSize = p.size(), i, j; 
    if(pS==pSize) return sS ==sSize; // if p goes to its end, then only if s also goes to its end to return true;

    if(p[pS+1]!='*')
    {
       if( sS<sSize && (p[pS]==s[sS] || p[pS] == '.')) return helper(s, p, sS+1, pS+1);
    }
    else
    {
        if(helper(s, p, sS,pS+2)) return true;
        while(sS<sSize && (p[pS]==s[sS] || p[pS] == '.')) if(helper(s,p, ++sS, pS+2)) return true;
    }
    return false;
}

bool isMatch(string s, string p) {
   helper(s, p, 0, 0); 
}
