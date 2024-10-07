#include "bits/stdc++.h"

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    int spare = 0;
    int minSpare = INT_MAX;
    int minIdx = 0;
    for (int i = 0; i < n; ++i) {
        spare += gas[i] - cost[i];
        if (spare <= minSpare) {
            minSpare = spare;
            minIdx = i;
        }
    }
    return spare < 0 ? -1 : (minIdx + 1) % n;
}