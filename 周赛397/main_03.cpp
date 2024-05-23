#include "vector"

using namespace std;

int maxScore(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int dp[n][m];
    int res = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mx1 = 0;
            int mx2 = 0;
            if (i + 1 < n) {
                mx1 = max(grid[i + 1][j], dp[i + 1][j]);
            }
            if (j + 1 < m) {
                mx2 = max(grid[i][j + 1], dp[i][j + 1]);
            }
            dp[i][j] = max(mx1, mx2);
            if (i == n - 1 && j == m - 1) {
                continue;
            }
            res = max(res, dp[i][j] - grid[i][j]);
        }
    }
    return res;
}