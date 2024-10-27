#include "bits/stdc++.h"

using namespace std;

vector<int> parent;

int Find(int index) {
    if (parent[index] != index) {
        parent[index] = Find(parent[index]);
    }
    return parent[index];
}

void Union(int index1, int index2) {
    parent[Find(index1)] = Find(index2);
}


vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (const auto &edge: edges) {
        if (Find(edge[0]) != Find(edge[1])) {
            Union(edge[0], edge[1]);
        } else {
            return {edge[0], edge[1]};
        }
    }
    return {};
}
