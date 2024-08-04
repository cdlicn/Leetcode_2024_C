#include "bits/stdc++.h"

using namespace std;

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        g[i].emplace_back(i + 1);
    }

    auto bfs = [&]() {
        vector<bool> vis(n, true);
        queue<int> q;
        q.emplace(0);
        vis[0] = false;
        int res = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                int t = q.front();
                q.pop();
                if (t == n - 1) {
                    return res;
                }
                for (auto &item: g[t]) {
                    if (vis[item]) {
                        q.emplace(item);
                        vis[item] = false;
                    }
                }
            }
            res++;
        }
        return -1;
    };

    vector<int> res;
    for (const auto &q: queries) {
        g[q[0]].emplace_back(q[1]);
        res.emplace_back(bfs());
    }
    return res;
}