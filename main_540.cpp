#include "bits/stdc++.h"

using namespace std;

int singleNonDuplicate(vector<int> &nums) {
    int lef = 0, rig = nums.size() - 1;
    while (lef < rig) {
        int mid = (rig - lef) / 2 + lef;
        if (mid % 2 == 0) {
            if (nums[mid] == nums[mid + 1]) {
                lef = mid + 1;
            } else {
                rig = mid;
            }
        } else {
            if (nums[mid] == nums[mid - 1]) {
                lef = mid + 1;
            } else {
                rig = mid;
            }
        }

    }
    return nums[lef];
}