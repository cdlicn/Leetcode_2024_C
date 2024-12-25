#include "bits/stdc++.h"

using namespace std;

int islandPerimeter(vector<vector<int>> &grid) {
    int res = 0, n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j]) {
                if (i == 0 || !grid[i - 1][j]) {
                    res++;
                }
                if (i == n - 1 || !grid[i + 1][j]) {
                    res++;
                }
                if (j == 0 || !grid[i][j - 1]) {
                    res++;
                }
                if (j == m - 1 || !grid[i][j + 1]) {
                    res++;
                }
            }
        }
    }
    return res;
}