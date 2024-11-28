#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;

int countOfPairs(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2001, 0));
    for (int i = 0; i <= nums[0]; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= nums[i]; ++j) {
            // arr1 要求前一个取值小于j
            // arr2 要求前一个取值大于等于 nums[i] - j ~ 2000
            for (int k = 0; k <= j; k++) {
                if (nums[i - 1] - k < nums[i] - j) {
                    continue;
                }
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }
    int res = 0;
    for (int j = 0; j <= 2000; ++j) {
        res = (res + dp[n - 1][j]) % MOD;
    }
    return res;
}