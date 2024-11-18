#include "bits/stdc++.h"

using namespace std;

int dic[9][2]{{0,  0},
              {0,  1},
              {0,  -1},
              {1,  0},
              {1,  -1},
              {1,  1},
              {-1, 0},
              {-1, 1},
              {-1, -1}};

vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
    int n = img.size(), m = img[0].size();
    vector<vector<int>> res(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cnt = 0;
            int s = 0;
            for (const auto &d: dic) {
                if (i + d[0] >= 0 && i + d[0] < n && j + d[1] >= 0 && j + d[1] < m) {
                    cnt += img[i + d[0]][j + d[1]];
                    s++;
                }
            }
            res[i][j] = cnt / s;
        }
    }
    return res;
}