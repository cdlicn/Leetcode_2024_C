#include "bits/stdc++.h"

using namespace std;

int maxNumOfMarkedIndices(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), lef = n / 2 - 1, rig = n - 1, res = 0;
    while (lef >= 0 && rig >= n / 2) {
        if (nums[lef] * 2 <= nums[rig]) {
            res += 2;
            lef--;
            rig--;
        } else {
            lef--;
        }
    }
    return res;
}