#include "bits/stdc++.h"

using namespace std;

int maximumLength(vector<int> &nums, int k) {
    unordered_map<int, vector<int>> fs;
    vector<int> mx(k + 2);
    for (int x: nums) {
        auto &f = fs[x];
        f.resize(k + 1);
        for (int j = k; j >= 0; j--) {
            f[j] = max(f[j], mx[j]) + 1;
            mx[j + 1] = max(mx[j + 1], f[j]);
        }
    }
    return mx[k + 1];
}