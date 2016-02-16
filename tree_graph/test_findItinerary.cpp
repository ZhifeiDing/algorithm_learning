#include "leetcode.hpp"

void test_findItinerary() {
    vector<pair<string, string> > tickets;
    tickets.push_back(make_pair("MUC","LHR"));
    tickets.push_back(make_pair("JFK","MUC"));
    tickets.push_back(make_pair("SFO","SJC"));
    tickets.push_back(make_pair("LHR","SFO"));
    for(auto ticket : tickets)
        cout << " [" << ticket.first << " , " << ticket.second << "] ";
    cout << endl;
    vector<string> r = findItinerary(tickets);
    cout << "[";
    for(auto ticket : r)
        cout << ticket << " ";
    cout << "]" << endl;

    // test case II
    tickets.resize(0);
    tickets.push_back(make_pair("JFK","SFO"));
    tickets.push_back(make_pair("JFK","ATL"));
    tickets.push_back(make_pair("SFO","ATL"));
    tickets.push_back(make_pair("ATL","JFK"));
    tickets.push_back(make_pair("ATL","SFO"));

    for(auto ticket : tickets)
        cout << " [" << ticket.first << " , " << ticket.second << "] ";
    cout << endl;
    r = findItinerary(tickets);
    cout << "[";
    for(auto ticket : r)
        cout << ticket << " ";
    cout << "]" << endl;
}
