#include "bits/stdc++.h"

using namespace std;

long long maximumValueSum(vector<vector<int>> &board) {
    int n = board.size(), m = board[0].size();
    typedef pair<int, int> pii;
    pii best[n][3];
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 3; k++) best[i][k] = {-1, -2e9};
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 3; k++)
                if (board[i][j] > best[i][k].second) {
                    for (int kk = 2; kk > k; kk--) best[i][kk] = best[i][kk - 1];
                    best[i][k] = {j, board[i][j]};
                    break;
                }
    }

    long long ans = -1e18;
    for (int i1 = 0; i1 < n; i1++)
        for (int k1 = 0; k1 < 3; k1++)
            for (int i2 = i1 + 1; i2 < n; i2++)
                for (int k2 = 0; k2 < 3; k2++)
                    if (best[i2][k2].first != best[i1][k1].first)
                        for (int i3 = i2 + 1; i3 < n; i3++)
                            for (int k3 = 0; k3 < 3; k3++)
                                if (best[i3][k3].first != best[i1][k1].first &&
                                    best[i3][k3].first != best[i2][k2].first) {
                                    ans = max(ans, (long long) best[i1][k1].second + best[i2][k2].second +
                                                   best[i3][k3].second);
                                    break;
                                }
    return ans;
}