#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    int n = nums.size();
    set<vector<int>> s;
    auto dfs = [&](auto dfs, vector<int> v, vector<bool> vis) {
        if (v.size() == n) {
            if (!s.contains(v)) {
                s.emplace(v);
                res.emplace_back(v);
            }
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