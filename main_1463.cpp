#include "vector"
#include "functional"

using namespace std;

int cherryPickup(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(n, -1))); // -1 表示没有计算过
    function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
        if (i == m || j < 0 || j >= n || k < 0 || k >= n) {
            return 0;
        }
        int &res = memo[i][j][k]; // 注意这里是引用
        if (res != -1) { // 之前计算过
            return res;
        }
        for (int j2 = j - 1; j2 <= j + 1; j2++) {
            for (int k2 = k - 1; k2 <= k + 1; k2++) {
                res = max(res, dfs(i + 1, j2, k2));
            }
        }
        res += grid[i][j] + (k != j ? grid[i][k] : 0);
        return res;
    };
    return dfs(0, 0, n - 1);
}