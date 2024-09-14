#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> memo;
int dis[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
};

int dfs(int i, int j, vector<vector<int>> &grid, int health) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || memo[i][j] >= health) {
        return false;
    }
    memo[i][j] = health;
    if (grid[i][j] == 1) {
        health -= 1;
    }
    if (health <= 0) {
        return false;
    }
    if (i == grid.size() - 1 && j == grid[0].size() - 1) {
        return true;
    }
    for (const auto &d: dis) {
        if (dfs(i + d[0], j + d[1], grid, health) > 0) {
            return true;
        }
    }
    return false;
}

bool findSafeWalk(vector<vector<int>> &grid, int health) {
    memo.resize(grid.size(), vector<int>(grid[0].size(), 0));
    return dfs(0, 0, grid, health);
}
/*
[[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
1
[[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]]
3
[[1,1,1],[1,0,1],[1,1,1]]
5
[[1,1,1,1]]
4
 */