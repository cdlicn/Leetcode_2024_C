#include "bits/stdc++.h"

using namespace std;

int maximumStrongPairXor(vector<int> &nums) {
    int res = -1;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) {
                res = max(nums[i] ^ nums[j], res);
            }
        }
    }
    return res;
}