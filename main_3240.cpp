#include "bits/stdc++.h"

using namespace std;

int minFlips(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int res = 0;
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            int c = grid[i][j] + grid[n - 1 - i][j] + grid[i][m - 1 - j] + grid[n - 1 - i][m - 1 - j];
            res += min(c, 4 - c);
        }
    }
    int diff = 0, cnt1 = 0;
    if (m % 2 && n % 2) {
        res += grid[n / 2][m / 2];
    }
    if (n % 2) {
        for (int i = 0; i < m / 2; ++i) {
            if (grid[n / 2][i] != grid[n / 2][m - 1 - i]) {
                diff++;
            } else {
                cnt1 += grid[n / 2][i] * 2;
            }
        }
    }
    if (m % 2) {
        for (int i = 0; i < n / 2; ++i) {
            if (grid[i][m / 2] != grid[n - 1 - i][m / 2]) {
                diff++;
            } else {
                cnt1 += grid[i][m / 2] * 2;
            }
        }
    }
    return res + (diff ? diff : cnt1 % 4);
}