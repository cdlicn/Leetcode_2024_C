#include "bits/stdc++.h"

using namespace std;

long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB) {
    int n = energyDrinkA.size();
    vector<long long> v1(n + 1, 0), v2(n + 1, 0);
    v1[1] = energyDrinkA[0];
    v2[1] = energyDrinkB[0];
    for (int i = 1; i < n; ++i) {
        v1[i + 1] = max(v1[i] + energyDrinkA[i], v2[i - 1] + energyDrinkA[i]);
        v2[i + 1] = max(v2[i] + energyDrinkB[i], v1[i - 1] + energyDrinkB[i]);
    }
    return max(v1[n], v2[n]);
}