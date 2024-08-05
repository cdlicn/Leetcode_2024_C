#include "bits/stdc++.h"

using namespace std;

// TODO 600. 不含连续1的非负整数
int findIntegers(int n) {
    int m = __lg(n); // n 的最高位
    vector<array<int, 2>> memo(m + 1, {-1, -1}); // -1 表示没有计算过
    auto dfs = [&](auto &&dfs, int i, bool pre1, bool is_limit) -> int {
        if (i < 0) {
            return 1;
        }
        if (!is_limit && memo[i][pre1] >= 0) { // 之前计算过
            return memo[i][pre1];
        }
        int up = is_limit ? n >> i & 1 : 1;
        int res = dfs(dfs, i - 1, false, is_limit && up == 0); // 填 0
        if (!pre1 && up == 1) { // 可以填 1
            res += dfs(dfs, i - 1, true, is_limit); // 填 1
        }
        if (!is_limit) {
            memo[i][pre1] = res; // 记忆化
        }
        return res;
    };
    return dfs(dfs, m, false, true); // 从高位到低位
}