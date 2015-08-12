#include "leetcode.hpp"

void test_findWords() {
  srand((unsigned int)time(NULL));
  int m = rand()%11;
  int n = rand()%11;
  vector<vector<char> > board(m, vector<char>(n));
  vector<string> words(m);
  cout << endl << "Boards : " << endl;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      char c = rand()%11 + 'a';
      board[i][j] = c;
      cout << c << " ";
    }
    cout << endl;
    int k = rand()%7 + 1;
    for(int j = 0; j < k; j++)
      words[i].push_back(rand()%11 + 'a');
  }
  cout << endl << "Words : " << endl;
  for(int i = 0; i < m; i++) {
    cout << words[i] << endl;
  }
  vector<string> r = findWords(board, words);
  cout << endl << "Find : " << endl;
  for(int i = 0; i < r.size(); i++)
    cout << r[i] << endl;
}
