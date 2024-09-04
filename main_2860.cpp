#include "bits/stdc++.h"

using namespace std;

int countWays(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int res = nums[0] > 0 ? 1 : 0;
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        res += nums[i - 1] < i && i < nums[i];
    }
    return res + 1;
}