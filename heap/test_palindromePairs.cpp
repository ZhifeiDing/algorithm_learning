#include "leetcode.hpp"

void test_palindromePairs() {
    vector<vector<string> > words = {{"abcd","dcba","lls","s","sssll"},
        {"abcd","dcba","lls","s","sssll","sll"},
        {"a",""}};
    for(int i = 0; i < words.size(); ++i) {
        cout << "Test : " << i << endl;
        cout << "words = ";
        for(auto &s : words[i]) {
            cout << s << "\t";
        }
        cout << endl;
        vector<vector<int> > r = palindromePairs(words[i]);
        cout << "r = [ ";
        for(auto &itr : r) {
            cout << "[" << itr[0] << ", " << itr[1] << "] ";
        }
        cout << " ] " << endl;
    }
}
