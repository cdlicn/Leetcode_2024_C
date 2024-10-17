#include "bits/stdc++.h"

using namespace std;

// TODO 3193. 统计逆序对的数目
const int MOD = 1'000'000'007;

int numberOfPermutations(int n, vector<vector<int>> &requirements) {
    vector<int> req(n, -1);
    req[0] = 0;
    for (auto &p: requirements) {
        req[p[0]] = p[1];
    }
    if (req[0]) {
        return 0;
    }

    int m = ranges::max(req);
    vector<vector<int>> f(n, vector<int>(m + 1));
    f[0][0] = 1;
    for (int i = 1; i < n; i++) {
        int mx = req[i] < 0 ? m : req[i];
        if (int r = req[i - 1]; r >= 0) {
            for (int j = r; j <= min(i + r, mx); j++) {
                f[i][j] = f[i - 1][r];
            }
        } else {
            for (int j = 0; j <= mx; j++) {
                for (int k = 0; k <= min(i, j); k++) {
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % MOD;
                }
            }
        }
    }
    return f[n - 1][req[n - 1]];
}