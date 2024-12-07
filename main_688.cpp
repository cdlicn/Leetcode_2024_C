#include "bits/stdc++.h"

using namespace std;

int dirs[8][2] = {{2,  1},
                  {1,  2},
                  {-1, 2},
                  {-2, 1},
                  {-2, -1},
                  {-1, -2},
                  {1,  -2},
                  {2,  -1}};
vector<vector<vector<double>>> memo;

double dfs(int n, int k, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    double &res = memo[k][i][j];
    if (res) {
        return res;
    }
    for (auto &[dx, dy]: dirs) {
        res += dfs(n, k - 1, i + dx, j + dy);
    }
    res /= 8;
    return res;
};

double knightProbability(int n, int k, int row, int column) {
    memo.resize(k + 1, vector<vector<double>>(n, vector<double>(n)));
    return dfs(n, k, row, column);
}