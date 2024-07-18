#include "bits/stdc++.h"

using namespace std;

bool canSortArray(vector<int>& nums) {
    for (int i = 0, n = nums.size(); i < n;) {
        int start = i;
        int ones = __builtin_popcount(nums[i++]);
        while (i < n && __builtin_popcount(nums[i]) == ones) {
            i++;
        }
        sort(nums.begin() + start, nums.begin() + i);
    }
    return ranges::is_sorted(nums);
}