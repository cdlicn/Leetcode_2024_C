#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    ranges::sort(nums);
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int num = nums[i];
        int lef = i + 1;
        int rig = n - 1;
        while (lef < rig) {
            int sum = nums[lef] + nums[rig] + num;
            if (sum == 0) {
                res.push_back({num, nums[lef], nums[rig]});
                while (lef < rig && nums[lef] == nums[++lef]);
                while (lef < rig && nums[rig] == nums[--rig]);
            } else if (sum < 0) {
                while (lef < rig && nums[lef] == nums[++lef]);
            } else {
                while (lef < rig && nums[rig] == nums[--rig]);
            }
        }
    }
    return res;
}