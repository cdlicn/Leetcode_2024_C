#include "bits/stdc++.h"

using namespace std;

int edgeScore(vector<int> &edges) {
    int res = 0, n = edges.size();
    vector<long long> vs(n);
    for (int from = 0; from < n; ++from) {
        int to = edges[from];
        vs[to] += from;
        if (vs[to] > vs[res] || vs[to] == vs[res] && to < res) {
            res = to;
        }
    }
    return res;
}