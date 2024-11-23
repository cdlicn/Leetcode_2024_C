#include "bits/stdc++.h"

using namespace std;

int winningPlayerCount(int n, vector<vector<int>> &pick) {
    map<int, map<int, int>> m;
    int res = 0;
    vector<bool> v(n, true);
    for (const auto &item: pick) {
        int x = item[0];
        int y = item[1];
        m[x][y]++;
        if (v[x] && m[x][y] == x + 1) {
            res++;
            v[x] = false;
        }
    }
    return res;
}