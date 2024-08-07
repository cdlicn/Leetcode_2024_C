#include "bits/stdc++.h"

using namespace std;

int massage(vector<int> &nums) {
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    int ppre = nums[0];
    int pre = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); ++i) {
        int tmp = max(ppre + nums[i], pre);
        ppre = pre;
        pre = tmp;
    }
    return max(pre, ppre);
}