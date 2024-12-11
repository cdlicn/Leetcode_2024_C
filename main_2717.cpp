#include "bits/stdc++.h"

using namespace std;

int semiOrderedPermutation(vector<int> &nums) {
    int i1 = -1, i2 = -1, n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 1) {
            i1 = i;
        }
        if (nums[i] == n) {
            i2 = i;
        }
    }
    return i1 < i2 ? i1 + n - i2 - 1 : i1 + n - i2 - 2;
}