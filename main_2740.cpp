#include "bits/stdc++.h"

using namespace std;

int findValueOfPartition(vector<int> &nums) {
    int res = INT_MAX;
    ranges::sort(nums);
    for (int i = 1; i < nums.size(); ++i) {
        res = min(nums[i] - nums[i - 1], res);
    }
    return res;
}