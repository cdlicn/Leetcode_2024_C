#include "bits/stdc++.h"

using namespace std;

// TODO 3098. 求出所有子序列的能量和

int n;
unordered_map<long long, int> memo;
const int mod = 1e9 + 7;

int dfs(vector<int> &nums, int i, int j, int k, int m) {
    if (i >= n) {
        return k == 0 ? m : 0;
    }
    if (n - i < k) {
        return 0;
    }
    long long key = (1LL * m) << 18 | (i << 12) | (j << 6) | k;
    if (memo.contains(key)) {
        return memo[key];
    }
    long long res = dfs(nums, i + 1, j, k, m);
    if (j == n) {
        res += dfs(nums, i + 1, i, k - 1, m);
    } else {
        res += dfs(nums, i + 1, i, k - 1, min(m, nums[i] - nums[j]));
    }
    res %= mod;
    memo[key] = res;
    return memo[key];
}

int sumOfPowers(vector<int> &nums, int k) {
    n = nums.size();
    sort(nums.begin(), nums.end());
    return dfs(nums, 0, n, k, INT_MAX);
}
