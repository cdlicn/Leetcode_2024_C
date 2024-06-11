#include "vector"

using namespace std;

void dfs(int x, int y, vector<vector<char>> &board) {
    if (x < 0 || x >= board.size() || y < 0 || y > board[0].size() || board[x][y] != 'X') {
        return;
    }
    board[x][y] = '.';
    dfs(x + 1, y, board);
    dfs(x - 1, y, board);
    dfs(x, y + 1, board);
    dfs(x, y - 1, board);
}


int countBattleships(vector<vector<char>> &board) {
    int res = 0;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 'X') {
                res++;
                dfs(i, j, board);
            }
        }
    }
    return res;
}

