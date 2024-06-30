#include "bits/stdc++.h"

using namespace std;

int dfs(vector<int> &nums, int now, int target) {
    if (now == nums.size()) {
        return target == 0 ? 1 : 0;
    }
    return dfs(nums, now + 1, target - nums[now]) + dfs(nums, now + 1, target + nums[now]);
}

int findTargetSumWays(vector<int> &nums, int target) {
    return dfs(nums, 0, target);
}