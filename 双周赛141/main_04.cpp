#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;

int numberOfWays(int n, int x, int y) {
//    vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
//    dp[0][0] = 1;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j <= x; j++) {
//            dp[i][j] = dp[i - 1][j] * (j + 1);
//            if (j > 0) {
//                dp[i][j] += dp[i - 1][j - 1] * y;
//            }
//            dp[i][j] %= MOD;
//        }
//    }
//    long long res = 0;
//    for (int j = 0; j <= x; j++) {
//        res += dp[n][j];
//        res %= MOD;
//    }
//    return res;
}
