#include "bits/stdc++.h"

using namespace std;

int minimumOperations(vector<vector<int>> &grid) {
    int res = 0;
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[j][i] <= grid[j - 1][i]) {
                res += grid[j - 1][i] + 1 - grid[j][i];
                grid[j][i] = grid[j - 1][i] + 1;
            }
        }
    }
    return res;
}