#include "bits/stdc++.h"

using namespace std;

int minimumCost(int m, int n, vector<int> &horizontalCut, vector<int> &verticalCut) {
    sort(horizontalCut.begin(), horizontalCut.end());
    sort(verticalCut.begin(), verticalCut.end());
    int h = 1, v = 1, res = 0;
    while (!horizontalCut.empty() || !verticalCut.empty()) {
        if (horizontalCut.empty() || (!verticalCut.empty() && verticalCut.back() > horizontalCut.back())) {
            res += verticalCut.back() * v;
            verticalCut.pop_back();
            h++;
        } else {
            res += horizontalCut.back() * h;
            horizontalCut.pop_back();
            v++;
        }
    }
    return res;
}