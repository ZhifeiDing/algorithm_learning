#include "leetcode.hpp"

void test_numIslands() {
  srand((unsigned int)time(NULL));
  int m = rand()%10;
  int n = rand()%10;
  vector<vector<char> > grid(m, vector<char>(n));
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      grid[i][j] = rand()%2 ? '1' : '0';
      cout << grid[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
  cout << "number of islands = " << numIslands_uf(grid) << endl;
  cout << "number of islands = " << numIslands(grid) << endl;
}
