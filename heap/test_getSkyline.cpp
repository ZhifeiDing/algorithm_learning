#include "leetcode.hpp"

bool cmp(vector<int> a, vector<int> b) {
  return a[0] < b[0];
}

void test_getSkyline() {
  srand((unsigned int)time(NULL));
  int n = rand()%13;
  int k = 3;
  vector<vector<int> > buildings;
  for(int i = 0; i < n; i++) {
    vector<int> t(k);
    for(int j = 0; j < k; j++) {
      t[j] = rand()%10;
    }
    sort(t.begin(), t.end());
    buildings.push_back(t);
  }
  sort(buildings.begin(), buildings.end(), cmp);
  for(int i = 0; i < n; i++) {
    cout << "[";
    for(int j = 0; j < k; j++) {
      cout << buildings[i][j] ;
      if( j != k - 1 )
        cout << ",";
    }
    cout << "]";
    if( i != n - 1 ) 
      cout << " ,";
  }
  cout << endl;
  vector<pair<int,int> > r = getSkyline(buildings);
  for(int i = 0; i < r.size(); i++) {
    cout << "[" << r[i].first << "," << r[i].second << "]";
  }
  cout << endl;
}
