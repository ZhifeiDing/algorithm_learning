#include "leetcode.hpp"

/*
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * 
 * click to show follow up.
 * 
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */
void fillColZeroes(vector<vector<int> > &matrix, int j) {
    for(int i = 0; i < matrix.size(); ++i)
        matrix[i][j] = 0;
}

void fillRowZeroes(vector<vector<int> > &matrix, int i) {
    for(int j = 0; j < matrix[0].size(); ++j)
        matrix[i][j] = 0;
}

void setZeroes(vector<vector<int>>& matrix) {
    bool firstRowZero = false, firstColZero = false;
    
    for(int i = 0; i < matrix.size(); ++i)
        if( matrix[i][0] == 0 ) {
            firstColZero = true;
            break;
        }
    for(int j = 0; j < matrix[0].size(); ++j)
        if( matrix[0][j] == 0 ) {
            firstRowZero = true;
            break;
        }
            
    for(int i = 0; i < matrix.size(); ++i)
        for(int j = 0; j < matrix[0].size(); ++j) {
            if( matrix[i][j] == 0 ) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    for(int i = 1; i < matrix.size(); ++i)
        if( matrix[i][0] == 0 )
            fillRowZeroes(matrix, i);
    for(int j = 1; j < matrix[0].size(); ++j)
        if( matrix[0][j] == 0 )
            fillColZeroes(matrix, j);
    if( firstRowZero )
        fillRowZeroes(matrix, 0);
    if( firstColZero )
        fillColZeroes(matrix, 0);
}
