#include "leetcode.hpp"

/*
 * There are N gas stations along a circular route, where the 
 * amount of gas at station i is gas[i].
 * 
 * You have a car with an unlimited gas tank and it costs cost[i] 
 * of gas to travel from station i to its next station (i+1). You 
 * begin the journey with an empty tank at one of the gas stations.
 * 
 * Return the starting gas station's index if you can travel around 
 * the circuit once, otherwise return -1.
 * 
 * Note:
 * The solution is guaranteed to be unique.
 */
bool canCompleteCircuitHelper_backward(vector<int> & r, int i) {
  int pre = 0;
  while(i != i) {
    if( pre + r[i] < 0 )
      return false;
    pre += r[i];
    if( i == 0 )
      i = r.size() - 1;
    else
      i--;
  }
  return true;
}

bool canCompleteCircuitHelper_forward(vector<int> & r, int i) {
  int pre = 0;
  while(i != i) {
    if( pre + r[i] < 0 )
      return false;
    pre += r[i];
    if( i == r.size() - 1 )
      i = 0;
    else
      i++;
  }
  return true;
}


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  vector<int> r;
  for(int i = 0; i < gas.size(); i++)
    r.push_back(gas[i] - cost[i]);

  int i = 0;
  while( i < r.size() ) {
    if( r[i] < 0 ) {
      i++;
      continue;
    } else if( canCompleteCircuitHelper_forward(r, i) || canCompleteCircuitHelper_backward(r, i) )
      break;
    else
      i++;
  }
  return i;
}
