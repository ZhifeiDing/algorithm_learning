/*
 * Question:  Given a sorted integer array where the range of 
 * elements are [0, 99] inclusive, return its missing ranges.  
 * For example, given [0, 1, 3, 50, 75], return [“2”, “4->49”, 
 * “51->74”, “76->99”]  
 */
#include "leetcode.hpp"
/*
 * Example Questions Candidate Might Ask:  
 * Q: What if the given array is empty?  
 * A: Then you should return [“0->99”] as those ranges are missing. 
 * Q: What if the given array contains all elements from the ranges? 
 * A: Return an empty list, which means no range is missing.  
 * Solution:  Compare the gap between two neighbor elements and 
 * output its range, simple as that right? This seems deceptively easy, 
 * except there are multiple edge cases to consider, such as the first 
 * and last element, which does not have previous and next element 
 * respectively. Also, what happens when the given array is empty? We 
 * should output the range “0->99”. As it turns out, if we could add two 
 * “artificial” elements, –1 before the first element and 100 after the 
 * last element, we could avoid all the above pesky cases. 
 * Further Thoughts: i. List out test cases.  ii.  You should be able to 
 * extend the above cases not only for the range [0,99], but any arbitrary 
 * range [start, end]. 
 */
list<string> findMissingRanges(vector<int> vars, int start, int end) {
  list<string> r;
  int n = vars.size();
  if( n == 0 ) {
    r.push_back(getRanges(start,end));
    return r;
  }
  if( vars[0] - start > 0 ) {
    r.push_back(getRanges(start,vars[0]-1));
  }
  for(int i = 1; i < n; i++) {
    if( vars[i] - vars[i-1] > 1 ) {
      r.push_back(getRanges(vars[i-1]+1,vars[i]-1));
    }
  }
  if( end - vars[n-1] > 0 ) {
    r.push_back(getRanges(vars[n-1]+1,end));
  }
  return r;
}
string getRanges(int from, int start) {
  stringstream ss;
  ss << from;
  if( start - from != 0 ) {
    ss << "->";
    ss << start;
  }
  return ss.str();
}
