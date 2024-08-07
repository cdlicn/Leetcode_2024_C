#include "bits/stdc++.h"

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.contains(nums[i]) && abs(i - m[nums[i]]) <= k) {
            return true;
        }
        m[nums[i]] = i;
    }
    return false;
}