#include "bits/stdc++.h"

using namespace std;

// TODO 52. N 皇后 II
int totalNQueens(int n) {
    int ans = 0;
    vector<int> col(n), diag1(n * 2 - 1), diag2(n * 2 - 1);
    auto dfs = [&](auto &&dfs, int r) {
        if (r == n) {
            ans++; // 找到一个合法方案
            return;
        }
        for (int c = 0; c < n; c++) {
            int rc = r - c + n - 1;
            if (!col[c] && !diag1[r + c] && !diag2[rc]) {
                col[c] = diag1[r + c] = diag2[rc] = true;
                dfs(dfs, r + 1);
                col[c] = diag1[r + c] = diag2[rc] = false; // 恢复现场
            }
        }
    };
    dfs(dfs, 0);
    return ans;
}