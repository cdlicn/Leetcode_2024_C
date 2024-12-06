#include "bits/stdc++.h"

using namespace std;

int numRookCaptures(vector<vector<char>> &board) {
    int dirs[4][2] = {{0,  -1},
                      {0,  1},
                      {-1, 0},
                      {1,  0}};
    int x0, y0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'R') {
                x0 = i;
                y0 = j;
            }
        }
    }
    int res = 0;
    for (auto &[dx, dy]: dirs) {
        int x = x0 + dx, y = y0 + dy;
        while (0 <= x && x < 8 && 0 <= y && y < 8 && board[x][y] == '.') {
            x += dx;
            y += dy;
        }
        if (0 <= x && x < 8 && 0 <= y && y < 8 && board[x][y] == 'p') {
            res++;
        }
    }
    return res;
}