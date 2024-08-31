#include "bits/stdc++.h"

using namespace std;

bool canMakeSquare(vector<vector<char>> &grid) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if ((grid[i][j] == 'B' ? 1 : 0) + (grid[i + 1][j] == 'B' ? 1 : 0) + (grid[i][j + 1] == 'B' ? 1 : 0) +
                (grid[i + 1][j + 1] == 'B' ? 1 : 0) != 2) {
                return true;
            }
        }
    }
    return false;
}