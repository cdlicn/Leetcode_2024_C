#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    int n = nums.size();
    auto dfs = [&](auto dfs, vector<int> v, vector<bool> vis) {
        if (v.size() == n) {
            res.emplace_back(v);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                v.emplace_back(nums[i]);
                dfs(dfs, v, vis);
                v.erase(v.end());
                vis[i] = false;
            }
        }
    };
    vector<int> v;
    vector<bool> vis(n, false);
    dfs(dfs, v, vis);
    return res;
}