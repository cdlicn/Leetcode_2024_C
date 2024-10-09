#include "bits/stdc++.h"

using namespace std;

// TODO 3171. 找到按位或最接近 K 的子数组
int minimumDifference(vector<int>& nums, int k) {
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        ans = min(ans, abs(x - k));
        // 如果 x 是 nums[j] 的子集，就退出循环
        for (int j = i - 1; j >= 0 && (nums[j] | x) != nums[j]; j--) {
            nums[j] |= x;
            ans = min(ans, abs(nums[j] - k));
        }
    }
    return ans;
}