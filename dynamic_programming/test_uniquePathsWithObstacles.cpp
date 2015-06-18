#include "leetcode.hpp"

void test_uniquePathsWithObstacles() {
  srand((unsigned int)time(NULL));
  int m = rand()%11;
  int n = rand()%11;

  vector<vector<int> > obstacleGrid(m, vector<int>(n, 0));
  obstacleGrid[rand()%m][rand()%n] = 1;
  //for(int i = 0; i < m; i++)
  //  for(int j = 0; j < n; j++)
  //    obstacleGrid[i][j] = rand()%2;

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++)
      cout << obstacleGrid[i][j] << " ";
    cout << endl;
  }
  cout << "Unique Path = " << uniquePathsWithObstacles(obstacleGrid) << endl;
}
