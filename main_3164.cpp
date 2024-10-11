#include "bits/stdc++.h"

using namespace std;

long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    long long res = 0;
    unordered_map<int, int> mp;
    for (auto n1: nums1) {
        if (n1 % k) {
            continue;
        }
        n1 /= k;
        for (int i = 1; i * i <= n1; i++) {
            if (n1 % i) {
                continue;
            }
            mp[i]++;
            if (i * i < n1) {
                mp[n1 / i]++;
            }
        }
    }
    for (const auto &n2: nums2) {
        res += mp.contains(n2) ? mp[n2] : 0;
    }
    return res;
}