#include "leetcode.hpp"
#include "twoSumDataStructure.hpp"

void twoSumADT_hash::add(const int x) {
  data.push_back(x);
  if( data.size() > 1 ) {
    for(int i = 0; i < data.size()-1; i++)
      twoSum[data[i]+x] = pair<int,int>(i,data.size()-1);
  }
}

bool twoSumADT_hash::find(const int x) {
  return twoSum.find(x) != twoSum.end();
}

void twoSumADT_hash::print() {
  print_array(data);
}

twoSumADT_hash::twoSumADT_hash(int x) {
  data.push_back(x);
}

void twoSumADT::add(const int x) {
  if( data.find(x) != data.end() )
    data[x] += 1;
  else
    data[x] = 1;
}

bool twoSumADT::find(const int x) {
  for(auto itr: data) {
    if( itr.first == x ) {
      if( itr.second >= 2 ) {
        return true;
      }
    } else if( data.find(x-itr.first) != data.end() )
      return true;
  }
  return false;
}

void twoSumADT::print() {
  for(auto itr: data) {
    for(int i = 0; i < itr.second; i++)
      cout << itr.first << " ";
  }
  cout << endl;
}

twoSumADT::twoSumADT(int x) {
  data[x] = 1;;
}
