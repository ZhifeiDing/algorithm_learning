#include "leetcode.hpp"

void test_findMinHeightTrees() {
  int n = 4;
  vector<pair<int,int> > edges;
  edges.push_back(make_pair(1,0));
  edges.push_back(make_pair(1,2));
  edges.push_back(make_pair(1,3));
  vector<int> r = findMinHeightTrees(n, edges);
  cout << "n = " << n << ", edges = [";
  for(auto itr : edges)
    cout << "[" << itr.first << ", " << itr.second << "] ";
  cout << "]" << endl;
  cout << " The minimum height tree root = ";
  for(auto i : r)
    cout << "[" << i << "] ";
  cout << endl;
  
  // second case
  n = 6;
  edges.resize(0);
  edges.push_back(make_pair(0,3));
  edges.push_back(make_pair(1,3));
  edges.push_back(make_pair(2,3));
  edges.push_back(make_pair(4,3));
  edges.push_back(make_pair(5,4));
  r = findMinHeightTrees(n, edges);
  cout << "n = " << n << ", edges = [";
  for(auto itr : edges)
    cout << "[" << itr.first << ", " << itr.second << "] ";
  cout << "]" << endl;
  cout << " The minimum height tree root = ";
  for(auto i : r)
    cout << "[" << i << "] ";
  cout << endl;
}
