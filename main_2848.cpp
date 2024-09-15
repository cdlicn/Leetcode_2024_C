#include "bits/stdc++.h"

using namespace std;

int numberOfPoints(vector<vector<int>> &nums) {
    set<int> s;
    for (const auto &n: nums) {
        for (int i = n[0]; i <= n[1]; i++) {
            s.emplace(i);
        }
    }
    return s.size();
}