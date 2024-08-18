#include "bits/stdc++.h"

using namespace std;

long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB) {
    int n = energyDrinkA.size();
    vector<pair<long long, long long>> f(n);
    f[0] = make_pair(energyDrinkA[0], energyDrinkB[0]);
    for (int i = 1; i < n; ++i) {
        f[i].first = max(f[i - 1].first + energyDrinkA[i],
                         f[i - 1].second);
        f[i].second = max(f[i - 1].second + energyDrinkB[i],
                          f[i - 1].first);
    }
    return max(f[n - 1].first, f[n - 1].second);
}


