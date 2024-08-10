#include "bits/stdc++.h"

using namespace std;

// TODO 1187. 使数组严格递增
int makeArrayIncreasing(vector<int> &a, vector<int> &b) {
    sort(b.begin(), b.end()); // 为能二分查找，对 b 排序
    int n = a.size();
    unordered_map<int, int> memo[n];
    function<int(int, int)> dfs = [&](int i, int pre) -> int {
        if (i < 0) {
            return 0;
        }
        if (auto it = memo[i].find(pre); it != memo[i].end()) {
            return it->second; // 之前计算过了
        }
        // 不替换 a[i]
        int res = a[i] < pre ? dfs(i - 1, a[i]) : INT_MAX / 2;
        // 二分查找 b 中小于 pre 的最大数的下标
        auto k = lower_bound(b.begin(), b.end(), pre);
        // a[i] 替换成小于 pre 的最大数
        if (k != b.begin()) {
            res = min(res, dfs(i - 1, *--k) + 1);
        }
        return memo[i][pre] = res;
    };
    int ans = dfs(n - 1, INT_MAX); // 假设 a[n-1] 右侧有个无穷大的数
    return ans < INT_MAX / 2 ? ans : -1;
}