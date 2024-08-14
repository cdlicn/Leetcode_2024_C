#include "bits/stdc++.h"

using namespace std;

vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<int> vs(n);
    for (int i = 1; i < n; i++) {
        vs[i] = nums[i - 1] % 2 == nums[i] % 2 ? i : vs[i - 1];
    }
    vector<bool> res;
    for (auto &q: queries) {
        res.push_back(vs[q[1]] <= q[0]);
    }
    return res;
}