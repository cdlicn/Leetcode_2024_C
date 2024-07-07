#include "bits/stdc++.h"

using namespace std;

vector<pair<int, int>> d{
        {0,  1},
        {1,  0},
        {0,  -1},
        {-1, 0},
        {1,  1},
        {1,  -1},
        {-1, 1},
        {-1, -1},
};

unordered_map<char, char> m{
        {'W', 'B'},
        {'B', 'W'}
};

bool dfs(int i, vector<vector<char>> &board, int x, int y, char color) {
    x += d[i].first;
    y += d[i].second;
    if (x >= board.size() || x < 0 || y >= board[0].size() || y < 0 || board[x][y] == '.') {
        return false;
    }
    if (board[x][y] == color) {
        return true;
    }
    return dfs(i, board, x, y, color);
}

bool checkMove(vector<vector<char>> &board, int rMove, int cMove, char color) {
    board[rMove][cMove] = color;
    for (int i = 0; i < 8; ++i) {
        int x = rMove + d[i].first;
        int y = cMove + d[i].second;
        if (x < board.size() && x >= 0 && y < board[0].size() && y >= 0
            && board[x][y] == m[color] &&
            dfs(i, board, x, y, color)) {
            return true;
        }
    }
    return false;
}

/*
[[".",".","W",".","B","W","W","B"],
 ["B","W",".","W",".","W","B","B"],
 [".","W","B","W","W",".","W","W"],
 ["W","W",".","W",".",".","B","B"],
 ["B","W","B","B","W","W","B","."],
 ["W",".","W",".","W","B","W","W"],
 ["B",".","B","B",".",".","B","B"],
 [".","W",".","W",".","W",".","W"]]
 */