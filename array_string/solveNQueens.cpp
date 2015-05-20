#include "leetcode.hpp"

int size;

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > r;
    vector<string> s(n, string(n,'.'));
    size = n;
    nQueens(r, s, 0);
    return r;
}

void nQueens(vector<vector<string> > & r, vector<string> & s, int row) {
    if( row == size ) {
        r.push_back(s);
        return;
    }
    for( int col = 0; col < size; col++ ) {
        if( isValid(s, row, col) ) {
            s[row][col] = 'Q';
            nQueens(r, s, row+1);
            s[row][col] = '.';
        }
    }
}

bool isValid( vector<string> & s, int row, int col) {
    for(int i = 0; i < row; i++)
        if( s[i][col] == 'Q' ) 
            return false;
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if( s[i][j] == 'Q' )
            return false;
    for(int i = row - 1, j = col + 1; i >= 0 && j < size; i--, j++)
        if( s[i][j] == 'Q' )
            return false;
    return true;
}

