#include "bits/stdc++.h"

using namespace std;

// TODO 2959. 关闭分部的可行集合数目
int numberOfSets(int n, int maxDistance, vector<vector<int>> &roads) {
    vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2)); // 防止加法溢出
    for (auto &e: roads) {
        int x = e[0], y = e[1], wt = e[2];
        g[x][y] = min(g[x][y], wt);
        g[y][x] = min(g[y][x], wt);
    }

    vector<vector<int>> f(n);
    auto check = [&](int s) -> bool {
        for (int i = 0; i < n; i++) {
            if ((s >> i) & 1) {
                f[i] = g[i];
            }
        }

        // Floyd 算法（只考虑在 s 中的节点）
        for (int k = 0; k < n; k++) {
            if (((s >> k) & 1) == 0) continue;
            for (int i = 0; i < n; i++) {
                if (((s >> i) & 1) == 0) continue;
                for (int j = 0; j < n; j++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }

        // 判断保留的节点之间的最短路是否均不超过 maxDistance
        for (int i = 0; i < n; i++) {
            if (((s >> i) & 1) == 0) continue;
            for (int j = 0; j < i; j++) {
                if ((s >> j) & 1 && f[i][j] > maxDistance) {
                    return false;
                }
            }
        }
        return true;
    };

    int ans = 0;
    for (int s = 0; s < (1 << n); s++) { // 枚举子集
        ans += check(s);
    }
    return ans;
}