#include "bits/stdc++.h"

using namespace std;

int incremovableSubarrayCount(vector<int> &nums) {
    int i = 0;
    int n = nums.size();
    while (i < n - 1 && nums[i] < nums[i + 1]) {
        i++;
    }
    if (i == n - 1) {
        return n * (n + 1) / 2;
    }
    int res = i + 2;
    for (int j = n - 1; j == n - 1 || nums[j] < nums[j + 1]; j--) {
        while (i >= 0 && nums[i] >= nums[j]) {
            i--;
        }
        res += i + 2;
    }
    return res;
}