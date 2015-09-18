#include "leetcode.hpp"

/*
 * Given a list of non negative integers, arrange them such that they 
 * form the largest number.
 * 
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 
 * 9534330.
 * 
 * Note: The result may be very large, so you need to return a string 
 * instead of an integer.
 */


string largestNumber(vector<int> & nums) {
  vector<string> str;
  for(auto i : nums)
    str.push_back(to_string(i));
  sort(str.begin(), str.end(), [](const string &s1, const string &s2) {
      return s1+s2 > s2+s1;
      });
  string s;
  for(auto i : str)
    s += i;
  if( s[0] == '0' )
    return "0";
  return s;
}
