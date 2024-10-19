#include "bits/stdc++.h"

using namespace std;

int minOperations(vector<int> &nums) {
    int res = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] != nums[i + 1]) {
            res++;
        }
    }
    return nums[0] == 0 ? res + 1 : res;
}