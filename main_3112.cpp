#include "bits/stdc++.h"

using namespace std;

vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear) {
    vector<vector<pair<int, int>>> es(n);
    for (auto e: edges) {
        es[e[0]].emplace_back(e[1], e[2]);
        es[e[1]].emplace_back(e[0], e[2]);
    }

    // 优先队列 Dijkstra算法
    vector<int> dis(n, -1);
    dis[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // 到 val 的距离为 key
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [l, u] = pq.top();
        pq.pop();
        if (l > dis[u]) {
            continue;
        }
        for (auto &[t, d]: es[u]) {
            int new_dis = l + d;
            if (new_dis < disappear[t] && (dis[t] == -1 || new_dis < dis[t])) {
                dis[t] = new_dis;
                pq.emplace(new_dis, t);
            }
        }
    }
    return dis;
}