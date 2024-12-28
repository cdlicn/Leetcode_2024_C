#include "bits/stdc++.h"

using namespace std;

bool isPossibleToSplit(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (const auto &n: nums) {
        mp[n]++;
        if (mp[n] > 2) {
            return false;
        }
    }
    return true;
}