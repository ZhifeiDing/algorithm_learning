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

void dfs(vector<vector<int> > &adjList, vector<bool> &visited, int idx = 0) {
    if( visited[idx] )
        return;
    visited[idx] = true;
    for(auto vertic : adjList[idx])
        dfs(adjList, visited, vertic);
}

// for a valid tree, we should be able to traverse all vertices from one vertice
bool validTree(int n, vector<pair<int,int> > &edges) {
    if( edges.size() != n - 1 )
        return false;
    vector<vector<int> > adjList(n);
    for(auto edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }
    vector<bool> visited(n,false);
    dfs(adjList, visited);
    bool res = true;
    for(auto v : visited)
        res &= v;
    return res;
}

// union find solution
bool validTree_UF(int n, vector<pair<int,int> > &edges) {
    if( edges.size() != n - 1 )
        return false;
    vector<int> adjList(n);
    for(auto edge : edges) {
        adjList[edge.first] = edge.second;
        adjList[edge.second] = edge.first;
    }


}