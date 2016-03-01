#include "leetcode.hpp"
/*
 *
 *Given an integer matrix, find the length of the longest increasing path.
 *
 *From each cell, you can either move to four directions: left, right, up or
 *down. You may NOT move diagonally or move outside of the boundary (i.e.
 *    wrap-around is not allowed).
 *
 *Example 1:
 *
 *nums = [
 *  [9,9,4],
 *  [6,6,8],
 *  [2,1,1]
 *]
 *Return 4
 *The longest increasing path is [1, 2, 6, 9].
 *
 *Example 2:
 *
 *nums = [
 *  [3,4,5],
 *  [3,2,6],
 *  [2,2,1]
 *]
 *Return 4
 *The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */
static vector<vector<int> > dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int dfs(vector<vector<int> > &matrix, int i, int j, vector<vector<int> > &cached) {
    if( cached[i][j] )
        return cached[i][j];

    for(auto dir : dirs) {
        int x = i + dir[0], y = j + dir[1];
        if( x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size() || matrix[x][y] <= matrix[i][j] )
            continue;
        cached[i][j] = max(cached[i][j], 1 + dfs(matrix, x, y, cached));
    }
    return cached[i][j];
}
int longestIncreasingPath(vector<vector<int> > &matrix) {
    int r = 0;
    int m = matrix.size();
    if( m == 0 )
        return r;
    int n = matrix[0].size();
    vector<vector<int> > cached(m, vector<int>(n,0));
    for(int i = 0; i < matrix.size(); ++i)
        for(int j = 0; j < matrix[0].size(); ++j) {
            r = max(r, dfs(matrix, i, j, cached));
        }
    return r;
}
