#include "bits/stdc++.h"

using namespace std;

// TODO 3130. 找出所有稳定的二进制数组 II
int MOD = 1'000'000'007;
vector<vector<array<int, 2>>> memo;

int dfs(int i, int j, int k, int limit) {
    if (i == 0) { // 递归边界
        return k == 1 && j <= limit;
    }
    if (j == 0) { // 递归边界
        return k == 0 && i <= limit;
    }
    int &res = memo[i][j][k]; // 注意这里是引用
    if (res != -1) { // 之前计算过
        return res;
    }
    if (k == 0) {
        // + MOD 保证答案非负
        res = ((long long) dfs(i - 1, j, 0, limit) + dfs(i - 1, j, 1, limit) +
               (i > limit ? MOD - dfs(i - limit - 1, j, 1, limit) : 0)) % MOD;
    } else {
        res = ((long long) dfs(i, j - 1, 0, limit) + dfs(i, j - 1, 1, limit) +
               (j > limit ? MOD - dfs(i, j - limit - 1, 0, limit) : 0)) % MOD;
    }
    return res;
}

int numberOfStableArrays(int zero, int one, int limit) {
    // -1 表示没有计算过
    memo.resize(zero + 1, vector<array<int, 2>>(one + 1, {-1, -1}));
    return (dfs(zero, one, 0, limit) + dfs(zero, one, 1, limit)) % MOD;
}