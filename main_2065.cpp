#include "bits/stdc++.h"

using namespace std;

// TODO 2065. 最大化一张图中的路径价值
int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int max_time) {
    int n = values.size();
    vector<vector<pair<int, int>>> g(n);
    for (auto &e: edges) {
        int x = e[0], y = e[1], t = e[2];
        g[x].emplace_back(y, t);
        g[y].emplace_back(x, t);
    }

    int ans = 0;
    vector<int> vis(n);
    vis[0] = true;
    auto dfs = [&](auto &&dfs, int x, int sum_time, int sum_value) -> void {
        if (x == 0) {
            ans = max(ans, sum_value);
            // 注意这里没有 return，还可以继续走
        }
        for (auto &[y, t]: g[x]) {
            if (sum_time + t > max_time) {
                continue;
            }
            if (vis[y]) {
                dfs(dfs, y, sum_time + t, sum_value);
            } else {
                vis[y] = true;
                // 每个节点的价值至多算入价值总和中一次
                dfs(dfs, y, sum_time + t, sum_value + values[y]);
                vis[y] = false; // 恢复现场
            }
        }
    };
    dfs(dfs, 0, 0, values[0]);
    return ans;
}