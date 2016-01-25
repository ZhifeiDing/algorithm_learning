#include "leetcode.hpp"
/*
 *
 *Given n nodes labeled from 0 to n - 1 and a list of undirected edges
 *(each edge is a pair of nodes), write a function to check whether these
 *edges make up a valid tree.
 *
 *For example:
 *
 *Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
 *
 *Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
 *
 *Hint:
 *
 *Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return?
 *Is this case a valid tree?
 *According to the definition of tree on Wikipedia: “a tree is an undirected
 *graph in which any two vertices are connected by exactly one path. In other
 *words, any connected graph without simple cycles is a tree.”
 *Note: you can assume that no duplicate edges will appear in edges. Since all
 *edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear
 *together inedges.
 */
bool isCycle(vector<pair<int,int> > &edges, int startpoint, int &targetpoint, vector<bool> visited) {
    for(int i = 0; i < edges.size(); ++i) {
        if( visited[i] )
            continue;
        visited[i] = true;
        if( edges[i].first == startpoint ) {
            if( edges[i].second == targetpoint || isCycle(edges, edges[i].second, targetpoint, visited) )
                return true;
        }
        if( edges[i].second == startpoint ) {
            if( edges[i].first == targetpoint || isCycle(edges, edges[i].first, targetpoint, visited) )
                return true;
        }
    }
    return false;
}

bool validTree(int n, vector<pair<int,int> > &edges) {
    if( edges.size() > n - 1 )
        return false;
    vector<bool> visited(n,false);
    for(int i = 0; i < edges.size(); ++i) {
        visited[i] = true;
        if( isCycle(edges, edges[i].first, edges[i].second, visited) )
            return false;
        visited[i] = false;
    }
    return true;
}