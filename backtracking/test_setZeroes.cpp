#include "leetcode.hpp"

void test_setZeroes() {
  srand((unsigned int)time(NULL));
  int m = rand()%10;
  int n = rand()%10;
  vector<vector<int> > board(m);
  for(int i = 0; i < m; ++i)
    gen_array(n, board[i]);

  for(int i = 0; i < m; ++i)
    print_array(board[i]);
  setZeroes(board);
  cout << "next : " << endl;
  for(int i = 0; i < m; ++i)
    print_array(board[i]);
}
