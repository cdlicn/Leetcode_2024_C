#include "bits/stdc++.h"

using namespace std;

int minFlips(vector<vector<int>> &grid) {
    int min1 = 0;
    int min2 = 0;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            if (grid[i][j] != grid[i][m - j - 1]) {
                min1++;
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n / 2; ++i) {
            if (grid[i][j] != grid[n - i - 1][j]) {
                min2++;
            }
        }
    }
    return min(min1, min2);
}