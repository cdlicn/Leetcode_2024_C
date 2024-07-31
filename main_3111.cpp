#include "bits/stdc++.h"

using namespace std;

int minRectanglesToCoverPoints(vector<vector<int>> &points, int w) {
    sort(points.begin(), points.end(), [](auto &p1, auto &p2) -> bool {
        return p1[0] < p2[0];
    });
    int res = 0;
    int pre = -1;
    for (const auto &p: points) {
        if (p[0] > pre) {
            res++;
            pre = p[0] + w;
        }
    }
    return res;
}