#include "bits/stdc++.h"

using namespace std;

int maximumLength(vector<int> &nums, int k) {
    int n = nums.size();
    vector<vector<int>> dp(k, vector(n, 0));
    int mx = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int m = (nums[j] + nums[i]) % k;
            dp[m][i] = max(dp[m][j] + 1, dp[m][i]);
            mx = max(mx, dp[m][i]);
        }
    }
    return mx + 1;
}
