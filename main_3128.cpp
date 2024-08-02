#include "bits/stdc++.h"

using namespace std;

long long numberOfRightTriangles(vector<vector<int>> &grid) {
    long long res = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<int> col(m, 0), row(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                col[j]++;
                row[i]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                res += (row[i] - 1) * (col[j] - 1);
            }
        }
    }
    return res;
}