#include "bits/stdc++.h"

using namespace std;

// TODO 3180. 执行操作可获得的最大总奖励 I
int maxTotalReward(vector<int> &rewardValues) {
    sort(rewardValues.begin(), rewardValues.end());
    int n = rewardValues.back();
    vector<int> dp(2 * n);
    dp[0] = 1;
    for (int x: rewardValues) {
        for (int k = 2 * x - 1; k >= x; k--) {
            if (dp[k - x]) {
                dp[k] = 1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < dp.size(); i++) {
        if (dp[i]) {
            res = i;
        }
    }
    return res;
}