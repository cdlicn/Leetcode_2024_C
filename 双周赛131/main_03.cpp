#include "bits/stdc++.h"

using namespace std;

vector<int> queryResults(int limit, vector<vector<int>> &queries) {
    unordered_map<int, int> m;
    vector<int> res;
    unordered_map<int, int> color;
    for (const auto &query: queries) {
        int s = color[query[0]];
        if (s != 0) {
            m[s]--;
            if (m[s] == 0) {
                m.erase(s);
            }
        }
        color[query[0]] = query[1];
        m[query[1]]++;
        res.push_back(m.size());
    }
    return res;
}
