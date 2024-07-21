#include "bits/stdc++.h"

using namespace std;

int minChanges(vector<int> &nums, int k) {
    int n = nums.size();
    int half = n / 2;
    map<int, int> diff;
    for (int i = 0; i < half; ++i) {
        diff[abs(nums[i] - nums[n - i - 1])]++;
    }
    int res = n;
    for (auto &[X, v]: diff) {
        if (res > half - v) {
            continue;
        }
        int tmp = 0;
        for (int i = 0; i < half; ++i) {
            int d = abs(nums[i] - nums[n - i - 1]);
            if (d != X) {
                if (min(nums[i], nums[n - i - 1]) + X > k && max(nums[i], nums[n - i - 1]) - X < 0) {
                    tmp += 2;
                } else {
                    tmp += 1;
                }
            }
        }
        res = min(tmp, res);
    }
    return res;
}