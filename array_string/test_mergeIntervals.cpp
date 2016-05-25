#include "leetcode.hpp"

void printIntervals(vector<Interval> &intervals) {
    cout << "intervals = [" << endl;
    for(auto &i : intervals)
        cout << "[" << i.start << "," << i.end << "] ";
    cout << endl;
}

void test_mergeIntervals() {
    vector<Interval> intervals;
    vector<Interval> r;
    intervals.push_back(Interval(1,4));
    intervals.push_back(Interval(9,10));
    intervals.push_back(Interval(2,3));
    intervals.push_back(Interval(4,7));
    intervals.push_back(Interval(12,40));
    r = mergeIntervals(intervals);
    printIntervals(intervals);
    printIntervals(r);
}
