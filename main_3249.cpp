#include "bits/stdc++.h"

using namespace std;

int res = 0;
vector<bool> vis;

int dfs(vector<vector<int>> &roads, int i) {
    int a = -1;
    int sum = 1;
    int add = 1;
    vis[i] = true;
    for (const auto &r: roads[i]) {
        if (vis[r]) {
            continue;
        }
        int tmp = dfs(roads, r);
        if (a == -1 || a == tmp) {
            a = tmp;
        } else {
            add = 0;
        }
        sum += tmp;
    }
    res += add;
    return sum;
}

int countGoodNodes(vector<vector<int>> &edges) {
    vis.resize(edges.size() + 1, false);
    vector<vector<int>> roads(edges.size() + 1);
    for (const auto &edge: edges) {
        roads[edge[0]].push_back(edge[1]);
        roads[edge[1]].push_back(edge[0]);
    }
    dfs(roads, 0);
    return res;
}