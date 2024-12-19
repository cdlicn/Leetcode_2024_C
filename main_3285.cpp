#include "bits/stdc++.h"

using namespace std;

vector<int> stableMountains(vector<int> &height, int threshold) {
    vector<int> res;
    for (int i = 0; i < height.size() - 1; ++i) {
        if (height[i] > threshold) {
            res.emplace_back(i + 1);
        }
    }
    return res;
}