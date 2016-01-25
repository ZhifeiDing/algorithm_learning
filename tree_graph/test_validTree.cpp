#include "leetcode.hpp"

void test_validTree() {
    srand((unsigned int)time(NULL));
    int n = rand()%10 + 1;
    int m = rand()%15;
    vector<pair<int,int> > edges;
    for(int i = 0; i < m; ++i) {
        edges.push_back(make_pair(rand()%n, rand()%n));
    }
    cout << "edges = " << endl;
    for(int i = 0; i < m; ++i) {
        cout << edges[i].first << " -> " << edges[i].second << endl;
    }
    string r = validTree(n, edges) ? " is valid tree " : " is not valid tree ";
    cout << r << endl;
}
