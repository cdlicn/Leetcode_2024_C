#include "bits/stdc++.h"

using namespace std;

int duplicateNumbersXOR(vector<int> &nums) {
    int res = 0;
    map<int, int> m;
    for (const auto &item: nums) {
        m[item]++;
    }
    for (const auto &[k, v]: m) {
        if (v == 2) {
            res ^= k;
        }
    }
    return res;
}