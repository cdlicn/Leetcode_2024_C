#include "bits/stdc++.h"

using namespace std;

vector<int> goodSubsetofBinaryMatrix(vector<vector<int>> &grid) {
    unordered_map<int, int> mask_to_idx;
    for (int i = 0; i < grid.size(); i++) {
        int mask = 0;
        for (int j = 0; j < grid[i].size(); j++) {
            mask |= grid[i][j] << j;
        }
        if (mask == 0) {
            return {i};
        }
        mask_to_idx[mask] = i;
    }

    for (auto [x, i]: mask_to_idx) {
        for (auto [y, j]: mask_to_idx) {
            if ((x & y) == 0) {
                return {min(i, j), max(i, j)};
            }
        }
    }
    return {};
}