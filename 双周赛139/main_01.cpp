#include "bits/stdc++.h"

using namespace std;

vector<int> stableMountains(vector<int> &height, int threshold) {
    vector<int> res;
    int n = height.size();
    for (int i = 1; i < n; ++i) {
        if (height[i - 1] > threshold) {
            res.emplace_back(i);
        }
    }
    return res;
}