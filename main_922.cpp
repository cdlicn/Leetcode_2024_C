#include "bits/stdc++.h"

using namespace std;

vector<int> sortArrayByParityII(vector<int> &nums) {
    int jI = 1, oI = 0;
    while (jI < nums.size() && oI < nums.size()) {
        while (jI < nums.size() && nums[jI] % 2 != 0) {
            jI += 2;
        }
        while (oI < nums.size() && nums[oI] % 2 == 0) {
            oI += 2;
        }
        if (jI < nums.size() && oI < nums.size()) {
            int tmp = nums[jI];
            nums[jI] = nums[oI];
            nums[oI] = tmp;
        }
    }
    return nums;
}