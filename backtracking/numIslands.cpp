#include "leetcode.hpp"

/*
 * Given a 2d grid map of '1's (land) and '0's (water), count the 
 * number of islands. An island is surrounded by water and is formed 
 * by connecting adjacent lands horizontally or vertically. You may 
 * assume all four edges of the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 11110
 * 11010
 * 11000
 * 00000
 * Answer: 1
 * 
 * Example 2:
 * 
 * 11000
 * 11000
 * 00100
 * 00011
 * Answer: 3
 */

void dfs(vector<vector<char> > & grid, int x, int y) {
    if( x == grid.size() || x < 0 || y == grid[0].size() || y < 0 || grid[x][y] == '0' )
        return;
    grid[x][y] = '0';
    dfs(grid, x,1+y);
    dfs(grid, x, y-1);
    dfs(grid, 1+x, y);
    dfs(grid, x-1, y);
}


int numIslands(vector<vector<char> >& grid) {
    int num = 0;
    for(int i = 0; i < grid.size(); i++) 
        for( int j = 0; j < grid[0].size(); j++)
            if( grid[i][j] == '1' ) {
                ++num;
                dfs(grid, i, j);
            }
    return num;
}

// union find solution 
// O(m*n)
class unionFind {
public:
  unionFind(int n) {
    count = n;
    id = new int[n];
    weight = new int[n];
    for(int i = 0; i < n; i++) {
      id[i] = i;
      weight[i] = 0;
    }
  }

  ~unionFind() {
    delete []id;
    delete []weight;
  }

  void unionPQ(int p, int q) {
    int i = getRoot(p);
    int j = getRoot(q);
    if( i == j )
      return;
    if( weight[j] < weight[i] )
      id[j] = i;
    else {
      id[i] = j;
      if( weight[i] == weight[j] )
        weight[j]++;
    }
    --count;
  }

  int getCount() {
    return count;
  }
private:
  int *id;
  int *weight;
  int count;
  int getRoot(int i) {
    while( i != id[i] ) {
      id[i] = id[id[i]];
      i = id[i];
    }
    return i;
  }
};
int numIslands_uf(vector<vector<char> > & grid) {
  if( grid.size() == 0 || grid[0].size() == 0 )
    return 0;
  int row = grid.size(), col = grid[0].size();
  unionFind uf(row*col+1);
  int dummyPoint = row * col;
  for(int i = 0; i < row; ++i) {
    for(int j = 0; j < col; ++j) {
      if( grid[i][j] == '1' ) {
        if( j != col - 1 && grid[i][j+1] == '1')
          uf.unionPQ(i*col + j, i*col + j + 1);
        if( i != row - 1 && grid[i+1][j] == '1')
          uf.unionPQ(i*col + j, (i+1)*col + j);
      } else {
        uf.unionPQ(i*col + j, dummyPoint);
      }
    }
  }
  return uf.getCount()-1;
}
