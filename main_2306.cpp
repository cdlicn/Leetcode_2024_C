#include "bits/stdc++.h"

using namespace std;

long long distinctNames(vector<string> &ideas) {
    unordered_set<string> st[26];
    for (const auto &s: ideas) {
        st[s[0] - 'a'].insert(s.substr(1));
    }
    long long res = 0;
    for (int i = 1; i < 26; ++i) {
        for (int j = 0; j < i; j++) {
            int m = 0; // 交集的大小
            for (auto &s: st[i]) {
                m += st[j].count(s);
            }
            res += (long long) (st[i].size() - m) * (st[j].size() - m);
        }
    }
    return res * 2;
}