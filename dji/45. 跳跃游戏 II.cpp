#include "bits/stdc++.h"

using namespace std;

int jump(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        int step = nums[i];
        for (int j = i + 1; j <= min(n - 1, i + step); ++j) {
            dp[j] = min(dp[i] + 1, dp[j]);
        }
    }
    return dp[n - 1];
}