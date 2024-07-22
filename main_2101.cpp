#include "bits/stdc++.h"

using namespace std;

int dfs(vector<vector<int>> &v, vector<bool> &visited, int idx) {
    int cnt = 1;
    for (auto &t: v[idx]) {
        if (!visited[t]) {
            visited[t] = true;
            cnt += dfs(v, visited, t);
        }
    }
    return cnt;
}

int maximumDetonation(vector<vector<int>> &bombs) {
    int n = bombs.size();
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long dx = bombs[i][0] - bombs[j][0];
            long long dy = bombs[i][1] - bombs[j][1];
            if (i != j && dx * dx + dy * dy <= (long long) bombs[i][2] * bombs[i][2]) {
                v[i].emplace_back(j);
            }
        }
    }
    int res = 1;
    for (int i = 0; i < n; ++i) {
        vector<bool> visited(n, false);
        visited[i] = true;
        res = max(res, dfs(v, visited, i));
    }
    return res;
}