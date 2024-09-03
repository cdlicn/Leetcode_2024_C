#include "bits/stdc++.h"

using namespace std;

long long maxStrength(vector<int> &nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    long long res = 1;
    int m = INT_MAX;
    int n0 = 0;
    for (const auto &n: nums) {
        if (n != 0) {
            res *= n;
        } else {
            n0++;
        }
        if (n < 0) {
            m = min(m, abs(n));
        }
    }
    if (n0 == nums.size() || (n0 == nums.size() - 1 && m != INT_MAX)) {
        return 0;
    }
    return res < 0 ? res * (-1) / m : res;
}