#include "leetcode.hpp"

/*
 * Unique Word Abbreviation
 * Total Accepted: 351 Total Submissions: 2106 Difficulty: Easy
 * An abbreviation of a word follows the form <first letter><number
 * ><last letter>. Below are some examples of word abbreviations:
 * a) it                      --> it    (no abbreviation)
 * 
 *      1
 * b) d|o|g                   --> d1g
 * 
 *               1    1  1
 *      1---5----0----5--8
 * c) i|nternationalizatio|n  --> i18n
 * 
 *               1
 *      1---5----0
 * d) l|ocalizatio|n          --> l10n
 * Assume you have a dictionary and given a word, find whether its 
 * abbreviation is unique in the dictionary. A word's abbreviation is 
 * unique if no other word from the dictionary has the same abbreviation.
 * Example: 
 * Given dictionary = [ "deer", "door", "cake", "card" ]
 * 
 * isUnique("dear") -> false
 * isUnique("cart") -> true
 * isUnique("cane") -> false
 * isUnique("make") -> true
 */
class ValidWordAbbr {
public:
  ValidWordAbbr(vector<string> dictionary) {
    for(auto itr : dictionary) {
      string s = itr;
      if( s.size() > 2 ) 
        s = s[0] + to_string(s.size()-2) + s[s.size()-1];
      if( abbrMap.find(s) == abbrMap.end() ) {
        abbrMap[s] = vector<string>{itr};
      } else {
        abbrMap[s].push_back(itr);
      }
    }
  }

  bool isUnique(string word) {
    string s = word;
    if( s.size() > 2 )
      s = s[0] + to_string(s.size()-2) + s[s.size()-1];
    if( abbrMap.find(s) == abbrMap.end() || (abbrMap[s].size() == 1 && abbrMap[s][0] == word ) )
      return true;
    return false;
  }
private:
  unordered_map<string,vector<string> > abbrMap;
};
// Your ValidWordAbbr object will be instantiated and called as such:  
// ValidWordAbbr vwa = new ValidWordAbbr(dictionary);  
// vwa.isUnique("Word");  
// vwa.isUnique("anotherWord");
