#include "bits/stdc++.h"

using namespace std;


// TODO 871. 最低加油次数
int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    int n = stations.size();
    vector<long> dp(n + 1);
    dp[0] = startFuel;
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (dp[j] >= stations[i][0]) {
                dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        if (dp[i] >= target) {
            return i;
        }
    }
    return -1;
}