#include "bits/stdc++.h"

using namespace std;

int minKnightMoves(int x, int y) {
    queue<pair<int, int>> q;
    vector<vector<int>> memo(1000, vector<int>(1000, 0));
    vector<pair<int, int>> dict = {
            {1,  2},
            {2,  1},
            {1,  -2},
            {2,  -1},
            {-1, -2},
            {-1, 2},
            {-2, 1},
            {-2, -1}
    };
    q.emplace(0, 0);
    int res = 0;
    memo[302][302] = 1;
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            pair<int, int> p = q.front();
            q.pop();
            if (p.first == x && p.second == y) {
                return res;
            }
            for (const auto &d: dict) {
                int nextX = p.first + d.first;
                int nextY = p.second + d.second;
                if (!memo[nextX + 302][nextY + 302]) {
                    q.emplace(nextX, nextY);
                    memo[nextX + 302][nextY + 302] = 1;
                }
            }
        }
        res++;
    }
    return -1;
}