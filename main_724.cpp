#include "bits/stdc++.h"

using namespace std;

int pivotIndex(vector<int> &nums) {
    int sum = 0;
    for (auto &item: nums) {
        sum += item;
    }
    int n = nums.size();
    int ls = 0;
    for (int i = 0; i < n; ++i) {
        sum -= nums[i];
        if (ls == sum) {
            return i;
        }
        ls += nums[i];
    }
    return -1;
}

