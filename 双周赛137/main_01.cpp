#include "bits/stdc++.h"

using namespace std;

vector<int> resultsArray(vector<int> &nums, int k) {
    vector<int> res;
    if (k > nums.size()) {
        return res;
    }
    if (k == 1) {
        for (const auto &item: nums) {
            res.push_back(item);
        }
        return res;
    }
    int n = nums.size();
    int i = 1;
    int idx = -1;
    for (; i < k; i++) {
        if (nums[i] != nums[i - 1] + 1) {
            idx = i;
        }
    }
    if (idx == -1) {
        res.push_back(nums[k - 1]);
    } else {
        res.push_back(-1);
    }
    for (i = k; i < n; i++) {
        if (nums[i] != nums[i - 1]+1) {
            idx = i;
        }
        if (nums[i] == nums[i - 1] + 1 && i - idx + 1 >= k) {
            res.push_back(nums[i]);
        } else {
            res.push_back(-1);
            idx = i;
        }

    }
    return res;
}

