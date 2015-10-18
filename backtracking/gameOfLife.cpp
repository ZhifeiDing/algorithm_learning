#include "leetcode.hpp"

/*
 * According to the Wikipedia's article: "The Game of Life, 
 * also known simply as Life, is a cellular automaton devised 
 * by the British mathematician John Horton Conway in 1970."
 * 
 * Given a board with m by n cells, each cell has an initial 
 * state live (1) or dead (0). Each cell interacts with its eight 
 * neighbors (horizontal, vertical, diagonal) using the following 
 * four rules (taken from the above Wikipedia article):
 * 
 * Any live cell with fewer than two live neighbors dies, as if 
 * caused by under-population.
 * Any live cell with two or three live neighbors lives on to 
 * the next generation.
 * Any live cell with more than three live neighbors dies, as if 
 * by over-population..
 * Any dead cell with exactly three live neighbors becomes a live 
 * cell, as if by reproduction.
 * Write a function to compute the next state (after one update) 
 * of the board given its current state.
 * 
 * Follow up: 
 * Could you solve it in-place? Remember that the board needs to be 
 * updated at the same time: You cannot update some cells first and 
 * then use their updated values to update other cells.
 * In this question, we represent the board using a 2D array. In 
 * principle, the board is infinite, which would cause problems when 
 * the active area encroaches the border of the array. How would you address 
 * these problems?
 */

int alive(vector<vector<int> > &board, int i, int j) {
  if( i < 0 || board.size() <= i || j < 0 || board[0].size() <= j )
    return 0;
  if( board[i][j] == 1 || board[i][j] == 2 )
    return 1;
  return 0;
}

int countAlive(vector<vector<int> > &board, int i, int j) {
  return alive(board, i+1, j) + alive(board, i+1, j+1) + alive(board, i+1, j-1) + alive(board, i, j+1)
    + alive(board, i, j-1) + alive(board, i-1, j) + alive(board,i-1,j-1) + alive(board, i-1, j+1);
}

void gameOfLife(vector<vector<int> > &board) {
  for(int i = 0; i < board.size(); ++i) 
    for(int j = 0; j < board[0].size(); ++j) {
      int alive = countAlive(board, i, j);
      if( board[i][j] == 1 ) {
        if( alive != 2 && alive != 3 )
          board[i][j] = 2;
      } else {
        if( alive == 3 )
          board[i][j] = 3;
      }
    }

  for(int i = 0; i < board.size(); ++i) 
    for(int j = 0; j < board[0].size(); ++j) {
      if( board[i][j] == 2 )
        board[i][j] = 0;
      else if( board[i][j] == 3 )
        board[i][j] = 1;
    }
}

