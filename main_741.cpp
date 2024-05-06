#include "vector"
#include "algorithm"

using namespace std;
// TODO 741. 摘樱桃
vector<vector<vector<int>>> memo;
int dfs(vector<vector<int>> &grid, int t, int j, int k) {
    if (j < 0 || k < 0 || t < j || t < k || grid[t - j][j] < 0 || grid[t - k][k] < 0) {
        return INT_MIN;
    }
    if (t == 0) {
        return grid[0][0];
    }
    int &res = memo[t][j][k];
    if (res != -1) {
        return res;
    }
    return res = max({dfs(grid, t - 1, j, k), dfs(grid, t - 1, j, k - 1), dfs(grid, t - 1, j - 1, k),
                      dfs(grid, t - 1, j - 1, k - 1)}) + grid[t - j][j] + (k != j ? grid[t - k][k] : 0);
}


int cherryPickup(vector<vector<int>> &grid) {
    int n = grid.size();
    memo = vector<vector<vector<int>>>(n * 2 - 1, vector<vector<int>>(n, vector<int>(n, -1)));
    return max(dfs(grid, n * 2 - 2, n - 1, n - 1), 0);
}

