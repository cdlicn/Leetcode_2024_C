#include "bits/stdc++.h"

using namespace std;

int minimumLevels(vector<int> &possible) {
    int n = possible.size();
    vector<int> pre(n + 1, 0);
    for (int i = 1; i < n + 1; ++i) {
        pre[i] = (possible[i - 1] == 1 ? 1 : -1) + pre[i - 1];
    }
    for (int i = 1; i < n; ++i) {
        if (pre[i] > pre[n] - pre[i]) {
            return i;
        }
    }
    return -1;
}