#include "bits/stdc++.h"

using namespace std;

long long maxScore(vector<int> &nums, int x) {
    long long n = nums.size();
    vector<long long> dp(n, 0);
    dp[0] = nums[0];
    long long mx = dp[0];
    // 偶数下标
    int maxEvenIndex = nums[0] % 2 == 0 ? 0 : -1;
    // 奇数下标
    int maxOddIndex = maxEvenIndex == 0 ? -1 : 0;
    for (int i = 1; i < n; i++) {
        long tmp = LONG_LONG_MIN;
        if (maxEvenIndex != -1) {
            tmp = max<long long>(tmp, nums[i] % 2 == 1 ? dp[maxEvenIndex] + nums[i] - x : dp[maxEvenIndex] + nums[i]);
        }
        if (maxOddIndex != -1) {
            tmp = max<long long>(tmp, nums[i] % 2 == 0 ? dp[maxOddIndex] + nums[i] - x : dp[maxOddIndex] + nums[i]);
        }
        dp[i] = tmp;
        mx = max<long long>(dp[i], mx);
        if (nums[i] % 2 == 0 && (maxEvenIndex == -1 || dp[i] > dp[maxEvenIndex])) {
            maxEvenIndex = i;
        }
        if (nums[i] % 2 == 1 && (maxOddIndex == -1 || dp[i] > dp[maxOddIndex])) {
            maxOddIndex = i;
        }
    }
    return mx;
}

