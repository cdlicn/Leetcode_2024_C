#include "bits/stdc++.h"

using namespace std;

// TODO 3244. 新增道路查询后的最短距离 II
vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
    vector<int> fa(n - 1);
    iota(fa.begin(), fa.end(), 0);

    // 非递归并查集
    auto find = [&](int x) -> int {
        int rt = x;
        while (fa[rt] != rt) {
            rt = fa[rt];
        }
        while (fa[x] != rt) {
            int tmp = fa[x];
            fa[x] = rt;
            x = tmp;
        }
        return rt;
    };

    vector<int> ans(queries.size());
    int cnt = n - 1; // 并查集连通块个数
    for (int qi = 0; qi < queries.size(); qi++) {
        int l = queries[qi][0], r = queries[qi][1] - 1;
        int fr = find(r);
        for (int i = find(l); i < r; i = find(i + 1)) {
            fa[i] = fr;
            cnt--;
        }
        ans[qi] = cnt;
    }
    return ans;
}