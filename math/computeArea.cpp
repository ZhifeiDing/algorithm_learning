#include "leetcode.hpp"

/*
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * 
 * Each rectangle is defined by its bottom left corner and top right 
 * corner as shown in the figure.
 * 
 * Rectangle Area
 * Assume that the total area is never beyond the maximum possible 
 * value of int.
 */


int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area = ( C - A ) * ( D - B ) + ( G - E ) * ( H - F );
    if( C <= E || H <= B || D<= F || G<= A )
        return area;
    int x1 = min(C,G);
    int x2 = max(A,E);
    int y1 = min(D,H);
    int y2 = max(B,F);
    return area - ( x1 - x2 ) * ( y1 - y2 );
}
