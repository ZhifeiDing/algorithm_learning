#include "leetcode.hpp"

/*
 * All DNA is composed of a series of nucleotides abbreviated as 
 * A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, 
 * it is sometimes useful to identify repeated sequences within 
 * the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings
 * ) that occur more than once in a DNA molecule.
 * 
 * For example,
 * 
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 * 
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 */

int str2int(string s) {

    int r = 0;
    for(int i = 0; i < s.size(); i++) {
      r = r << 2;
      if( s[i] == 'A' ) 
         r += 0;
      else if( s[i] == 'C' ) 
         r += 1;
      else if( s[i] == 'G' ) 
         r += 2;
      else if( s[i] == 'T' ) 
         r += 3;
    }
    return r;
}

vector<string> findRepeatedDnaSequences(string s) {
    const int len = 10;
    vector<string> r;
    unordered_map<int,int> seqMap;
    int i = 0;
    while( i + len < s.size() + 1 ) {
        int t = str2int(s.substr(i,len));
        if( seqMap.find(t) == seqMap.end() ) {
            seqMap[t] = 1;
        } else if( seqMap[t] == 1 ) {
            seqMap[t] = 2;
            r.push_back(s.substr(i,len));
        }
        i++;
    }
    return r;
}
