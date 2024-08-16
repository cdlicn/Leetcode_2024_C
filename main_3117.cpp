#include "bits/stdc++.h"

using namespace std;

// TODO 3117. 划分数组得到最小的值之和
int minimumValueSum(vector<int> &nums, vector<int> &andValues) {
    const int INF = INT_MAX / 2; // 除 2 防止下面 + nums[i] 溢出
    int n = nums.size(), m = andValues.size();
    unordered_map<long long, int> memo;
    auto dfs = [&](auto &&dfs, int i, int j, int and_) -> int {
        if (n - i < m - j) { // 剩余元素不足
            return INF;
        }
        if (j == m) { // 分了 m 段
            return i == n ? 0 : INF;
        }
        and_ &= nums[i];
        // 三个参数压缩成一个 long long
        long long mask = (long long) i << 36 | (long long) j << 32 | and_;
        if (memo.contains(mask)) { // 之前计算过
            return memo[mask];
        }
        int res = dfs(dfs, i + 1, j, and_); // 不划分
        if (and_ == andValues[j]) { // 划分，nums[i] 是这一段的最后一个数
            res = min(res, dfs(dfs, i + 1, j + 1, -1) + nums[i]);
        }
        return memo[mask] = res; // 记忆化
    };
    int ans = dfs(dfs, 0, 0, -1);
    return ans < INF ? ans : -1;
}
