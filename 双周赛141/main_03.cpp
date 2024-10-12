#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;

int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
//    int n = source.size();
//    int m = pattern.size();
//    int t = targetIndices.size();
//    vector<vector<int>> nextMatch(n + 1, vector<int>(m, -1));
//    for (int i = n - 1; i >= 0; --i) {
//        for (int j = 0; j < m; ++j) {
//            if (source[i] == pattern[j]) {
//                nextMatch[i][j] = i;
//            }
//            if (i < n - 1) {
//                nextMatch[i][j] = max(nextMatch[i][j], nextMatch[i + 1][j]);
//            }
//        }
//    }
//    vector<int> dp(t + 1, 0);
//    for (int i = 1; i <= t; ++i) {
//        int idx = targetIndices[i - 1];
//        bool canDelete = true;
//        int currentPos = 0;
//        for (int j = 0; j < m; ++j) {
//            if (currentPos >= idx) {
//                currentPos++;
//            }
//            if (currentPos >= n) {
//                canDelete = false;
//                break;
//            }
//            currentPos = nextMatch[currentPos][j];
//            if (currentPos == -1) {
//                canDelete = false;
//                break;
//            }
//        }
//        if (canDelete) {
//            dp[i] = dp[i - 1] + 1;
//        } else {
//            dp[i] = dp[i - 1];
//        }
//    }
//    return dp[t];
}