#include "bits/stdc++.h"

using namespace std;

vector<int> sortedSquares(vector<int> &nums) {
//    for (int &num: nums) {
//        num *= num;
//    }
//    sort(nums.begin(),nums.end());
//    return nums;
    int n = nums.size(), lef = 0, rig = n - 1, i = n - 1;
    vector<int> res(n);
    while (lef <= rig) {
        if (abs(nums[lef]) > abs(nums[rig])) {
            res[i--] = nums[lef] * nums[lef];
            lef++;
        } else {
            res[i--] = nums[rig] * nums[rig];
            rig--;
        }
    }
    return res;
}