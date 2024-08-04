#include "bits/stdc++.h"

using namespace std;

class neighborSum {
private:
    vector<vector<int>> grid;
    int n = 0;
    int m = 0;
public:
    neighborSum(vector<vector<int>> &grid) {
        this->grid = grid;
        this->n = grid.size();
        this->m = grid[0].size();
    }

    int adjacentSum(int value) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == value) {
                    int sum = 0;
                    if (i - 1 >= 0) {
                        sum += grid[i - 1][j];
                    }
                    if (i + 1 < n) {
                        sum += grid[i + 1][j];
                    }
                    if (j - 1 >= 0) {
                        sum += grid[i][j - 1];
                    }
                    if (j + 1 < m) {
                        sum += grid[i][j + 1];
                    }
                    return sum;
                }
            }
        }
        return 0;
    }

    int diagonalSum(int value) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == value) {
                    int sum = 0;
                    if (i - 1 >= 0) {
                        if (j - 1 >= 0) {
                            sum += grid[i - 1][j - 1];
                        }
                        if (j + 1 < m) {
                            sum += grid[i - 1][j + 1];
                        }
                    }
                    if (i + 1 < n) {
                        if (j - 1 >= 0) {
                            sum += grid[i + 1][j - 1];
                        }
                        if (j + 1 < m) {
                            sum += grid[i + 1][j + 1];
                        }
                    }
                    return sum;
                }
            }
        }
        return 0;
    }
};