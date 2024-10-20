#include "bits/stdc++.h"

using namespace std;

int smallestRangeI(vector<int> &nums, int k) {
    int mx = INT_MIN, mn = INT_MAX;
    for (const auto &n: nums) {
        mx = max(n, mx);
        mn = min(n, mn);
    }
    return max(mx - mn - 2 * k, 0);
}