#include "bits/stdc++.h";

using namespace std;

vector<int> fallingSquares(vector<vector<int>> &positions) {
    int n = positions.size();
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        int lef = positions[i][0];
        int rig = lef + positions[i][1] - 1;
        h[i] = positions[i][1];
        for (int j = 0; j < i; j++) {
            int lef2 = positions[j][0];
            int rig2 = lef2 + positions[j][1] - 1;
            if (rig >= lef2 && rig2 >= lef) {
                h[i] = max(h[i], h[j] + positions[i][1]);
            }
        }
    }
    for (int i = 1; i < n; i++) {
        h[i] = max(h[i], h[i - 1]);
    }
    return h;
}