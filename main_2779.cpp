#include "bits/stdc++.h"

using namespace std;

int maximumBeauty(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    vector<int> dp(nums[nums.size() - 1] + k + 2, 0);
    for (int num: nums) {
        dp[max(num - k, 0)]++;
        dp[num + k + 1]--;
    }
    int mx = 0, cnt = 0;
    for (int i = 0; i <= nums[nums.size() - 1] + k; i++) {
        cnt += dp[i];
        mx = max(cnt, mx);
    }
    return mx;
}