#include "bits/stdc++.h"

using namespace std;

double minimumAverage(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    double res = 99999999;
    int n = nums.size();
    for (int i = 0; i < n / 2; i++) {
        res = min((1.0 * nums[i] + nums[n - i - 1]) / 2, res);
    }
    return res;
}