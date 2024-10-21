#include "bits/stdc++.h"

using namespace std;

int smallestRangeII(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int res = nums[nums.size() - 1] - nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int mx = max(nums[i - 1] + k, nums.back() - k);
        int mn = min(nums[0] + k, nums[i] - k);
        res = min(res, mx - mn);
    }
    return res;
}
