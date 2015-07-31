#include "leetcode.hpp"

/*
 * Given a string of numbers and operators, return all possible results 
 * from computing all the different possible ways to group numbers and 
 * operators. The valid operators are +, - and *.
 * 
 * 
 * Example 1
 * Input: "2-1-1".
 * 
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 * Output: [0, 2]
 * 
 * 
 * Example 2
 * Input: "2*3-4*5"
 * 
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 * Output: [-34, -14, -10, -10, 10]
 */

vector<int> diffWaysToCompute(string input) {
  vector<int> r;
  auto cutPoint = input.find_first_of("+-*",0);
  if( cutPoint == string::npos )
    return vector<int>(1, stoi(input));
  do {
    for( auto itr1 : diffWaysToCompute(input.substr(0,cutPoint)) ) {
      for( auto itr2 : diffWaysToCompute(input.substr(cutPoint+1)) ) {
          if( input[cutPoint] == '+' ) 
            r.push_back(itr1 + itr2);
          else if( input[cutPoint] == '-' ) 
            r.push_back(itr1 - itr2);
          else 
            r.push_back(itr1 * itr2);
      }
    }
  } while( (cutPoint = input.find_first_of("+-*",cutPoint+1)) != string::npos );
  return r;
}

/*
 * dynamic programming -- key point : many expression have been calculated, we could take advantage of it.
 */
vector<int> diffWaysToComputeDP(string input, unordered_map<string, vector<int> > & expRecord) {
  vector<int> r;
  auto cutPoint = input.find_first_of("+-*",0);
  if( cutPoint == string::npos ) {
    r.push_back(atoi(input.c_str()));
    expRecord[input] = r;
    return r;
  }
  do {
    vector<int> r1, r2;
    if( expRecord.find(input.substr(0,cutPoint)) == expRecord.end() )
      r1 = diffWaysToComputeDP(input.substr(0,cutPoint), expRecord);
    else
      r1 = expRecord[input.substr(0,cutPoint)];

    if( expRecord.find(input.substr(cutPoint+1)) == expRecord.end() )
      r2 = diffWaysToComputeDP(input.substr(cutPoint+1), expRecord);
    else
      r2 = expRecord[input.substr(cutPoint+1)];

    for(auto itr1 : r1)
      for(auto itr2 : r2)
        if( input[cutPoint] == '-' )
          r.push_back(itr1 - itr2);
        else if( input[cutPoint] == '+' )
          r.push_back(itr1 + itr2);
        else
          r.push_back(itr1 * itr2);
  } while( ( cutPoint = input.find_first_of("+-*",cutPoint + 1) ) != string::npos );

  expRecord[input] = r;
  return r;
}

vector<int> diffWaysToCompute_DP(string input) {
  unordered_map<string, vector<int> > expRecord;
  return diffWaysToComputeDP(input, expRecord);
}
