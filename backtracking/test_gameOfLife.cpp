#include "leetcode.hpp"

void test_gameOfLife() {
  srand((unsigned int)time(NULL));
  int m = rand()%10;
  int n = rand()%10;
  vector<vector<int> > board(m);
  for(int i = 0; i < m; ++i)
    gen_array(n, board[i],2, false);

  for(int i = 0; i < m; ++i)
    print_array(board[i]);

  gameOfLife(board);
  cout << endl << " next : " << endl;
  for(int i = 0; i < m; ++i)
    print_array(board[i]);
}
