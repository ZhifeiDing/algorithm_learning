#include "leetcode.hpp"
/*
 *
 *Given a non-empty array of integers, return the k most frequent elements.
 *
 *For example,
 *Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 *Note:
 *You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 *Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> valCnt;
    for(auto itr : nums)
        ++valCnt[itr];

    //using my_pq_t = unordered_map<int,int>;
    //using my_container_t = vector<my_pq_t>;
    auto my_comp =
        [](const pair<int,int>& e1, const pair<int,int>& e2)
        { return e1.second < e2.second; };

    priority_queue<pair<int,int>,vector<pair<int,int> >,decltype(my_comp)> pq(valCnt.cbegin(), valCnt.cend(),my_comp);

    vector<int> r;
    while( k-- ) {
        r.push_back(pq.top().first);
        pq.pop();
    }
    return r;
}