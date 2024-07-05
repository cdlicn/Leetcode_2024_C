#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> mxV(n, 0);
    vector<pair<int, int>> pv;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == -1) {
                pv.emplace_back(i, j);
            } else {
                mxV[j] = max(mxV[j], matrix[i][j]);
            }
        }
    }
    for (auto [a, b]: pv) {
        matrix[a][b] = mxV[b];
    }
    return matrix;
}