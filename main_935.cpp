#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;
vector<vector<int>> memo;
vector<vector<int>> steps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4}
};

int dfs(int n, int i) {
    if (n == 0) {
        return 1;
    }
    int &res = memo[n][i];
    if (res) {
        return res;
    }
    for (const auto &step: steps[i]) {
        res = (res + dfs(n - 1, step) % MOD) % MOD;
    }
    return res;
}

int knightDialer(int n) {
    memo.resize(n, vector<int>(10, 0));
    int res = 0;
    for (int i = 0; i < 10; ++i) {
        res = (res + dfs(n - 1, i) % MOD) % MOD;
    }
    return res;
}