#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> res;

void dfs(int i, vector<int> &nums, vector<int> &vs) {
    if (i == nums.size()) {
        res.push_back(vs);
        return;
    }
    vs.push_back(nums[i]);
    dfs(i + 1, nums, vs);
    vs.erase(vs.end());
    while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
        i++;
    }
    dfs(i + 1, nums, vs);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    ranges::sort(nums);
    vector<int> vs;
    dfs(0, nums, vs);
    return res;
}