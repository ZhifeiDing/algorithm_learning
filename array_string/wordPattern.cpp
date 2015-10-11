#include "leetcode.hpp"

/*
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * patterncontains only lowercase alphabetical letters, and str contains words 
 * separated by a single space. Each word in str contains only lowercase alphabetical 
 * letters.
 * Both pattern and str do not have leading or trailing spaces.
 * Each letter in pattern must map to a word with length that is at least 1.
 */

void split(string &str, string delim, vector<string> & words) {
    size_t last = 0;
    size_t found = str.find_first_of(" ", 0);
    while( found != string::npos ) {
        words.push_back(str.substr(last, found - last));
        last = found + 1;
        found = str.find_first_of(" ", last);
    }
    if( last < str.size() )
        words.push_back(str.substr(last, str.size()-last));
}
bool wordPattern(string pattern, string str) {
    vector<string> words;
    split(str, " ", words);
    unordered_map<char, string> c2s;
    unordered_set<string> s;
    
    if( words.size() != pattern.size() )
        return false;
    for(int i = 0; i < words.size(); ++i) {
        if( c2s.find(pattern[i]) == c2s.end() ) {
          if( s.find(words[i]) != s.end() )
            return false;

          s.insert(words[i]);
          c2s[pattern[i]] = words[i];
        } else if( c2s[pattern[i]] != words[i] )
            return false;
    }
    return true;
}

// solution with stringstream
bool wordPattern_stringstream(string pattern, string str) {
  unordered_map<char, string> c2s;
  unordered_set<string> s;
  istringstream ss(str);
  for(int i = 0; i < pattern.size(); ++i) {
    ss >> str;
    if( c2s.find(pattern[i]) == c2s.end() ) {
      if( s.find(str) != s.end() )
        return false;
      s.insert(str);
      c2s[pattern[i]] = str;
    } else if( c2s[pattern[i]] != str )
      return false;
  }
  if( !ss.eof() )
    return false;

  return true;
}
