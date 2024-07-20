#include "bits/stdc++.h"

using namespace std;

int minimumMoves(vector<vector<int>> &grid) {
    vector<pair<int, int>> from;
    vector<pair<int, int>> to;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] > 1) {
                for (int k = 1; k < grid[i][j]; ++k) {
                    from.emplace_back(i, j);
                }
            } else if (grid[i][j] == 0) {
                to.emplace_back(i, j);
            }
        }
    }
    int res = INT_MAX;
    do {
        int tmp = 0;
        for (int i = 0; i < from.size(); ++i) {
            tmp += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
        }
        res = min(res, tmp);
    } while (next_permutation(from.begin(), from.end()));
    return res;
}