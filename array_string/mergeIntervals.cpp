#include "leetcode.hpp"
/*
 *
 *Given a collection of intervals, merge all overlapping intervals.
 *
 *For example,
 *Given [1,3],[2,6],[8,10],[15,18],
 *return [1,6],[8,10],[15,18].
 */
vector<Interval> mergeIntervals(vector<Interval>& intervals) {
    auto my_comp =
        [](const Interval &e1, const Interval &e2)
        { return e1.start < e2.start; };
    vector<Interval> r;

    if( intervals.size() == 0 )
        return r;

    sort(intervals.begin(), intervals.end(), my_comp);
    Interval interval = intervals[0];

    for(int i = 1; i < intervals.size(); ++i) {
        if( intervals[i].start <= interval.end )
            interval.end = max(interval.end,intervals[i].end);
        else {
            r.push_back(interval);
            interval = intervals[i];
        }
    }
    r.push_back(interval);
    return r;
}
