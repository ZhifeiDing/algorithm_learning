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
static const vector<vector<int> > dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

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
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j) {
            r = max(r, 1 + dfs(matrix, i, j, cached));
        }
    return r;
}

int longestIncreasingPath_lambda(vector<vector<int> > &matrix) {
    int r = 0;
    int m = matrix.size();
    if( m == 0 )
        return r;
    int n = matrix[0].size();
    vector<vector<int> > cached(m, vector<int>(n,0));
    function<int(int,int)> dfs = [&] (int x, int y) {
        if( cached[x][y] )
            return cached[x][y];
        for(auto dir : dirs) {
            int xx = x + dir[0], yy = y + dir[1];
            if( xx < 0 || yy < 0 || xx >= matrix.size() || yy >= matrix[0].size() || matrix[xx][yy] <= matrix[x][y] )
                continue;
            cached[x][y] = max(cached[x][y], 1 + dfs(xx,yy));
        }
        return cached[x][y];
    };
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j) {
            r = max(r, 1 + dfs(i, j));
        }
    return r;
}

// iterative solution
int longestIncreasingPath_iterative(vector<vector<int> > &matrix) {

    int r = 0;
    int m = matrix.size();
    if( m == 0 )
        return r;
    int n = matrix[0].size();

    int cnt = m * n;
    while( cnt ) {
        vector<pair<int,int> > remove;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
               if( matrix[i][j] == INT_MIN )
                   continue;
               bool up = i == 0 || matrix[i][j] >= matrix[i-1][j];
               bool down = i == m-1 || matrix[i][j] >= matrix[i+1][j];
               bool left = j == 0 || matrix[i][j] >= matrix[i][j-1];
               bool right = j == n-1 || matrix[i][j] >= matrix[i][j+1];
               if( up && down && left && right )
                   remove.push_back(make_pair(i,j));
            }
        for(auto rem : remove) {
            --cnt;
            matrix[rem.first][rem.second] = INT_MIN;
        }
        ++r;
    }
    return r;
}
