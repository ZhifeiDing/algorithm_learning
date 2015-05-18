#include "leetcode.hpp"

void gen_array(int n, vector<int> & data, int base) {
  srand((unsigned int)time(NULL));
  for(int i = 0; i < n; i++)
    data.push_back( rand() % base );
}

void print_array(vector<int> & data) {
  for(int i = 0; i < data.size(); i++)
    cout << data[i] << " ";
  cout << endl;
}

void print_2d_array(vector<vector<int> > & data) {
  for(int i = 0; i < data.size(); i++) {
    for(int j = 0; j < data[i].size(); j++)
      cout << data[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}
