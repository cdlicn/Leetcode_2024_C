#include "bits/stdc++.h"

using namespace std;

long long countAlternatingSubarrays(vector<int> &nums) {
    long long res = 0;
    int n = nums.size();
    int pre = 0;
    long long l = 0;
    for (int i = 1; i < n; ++i) {
        if (nums[i] == nums[i - 1]) {
            l = i - pre;
            res += l * (l + 1) >> 1;
            pre = i;
            cout << res << endl;
        }
    }
    if (pre == nums.size() - 1) {
        res++;
    } else {
        l = n - pre;
        res += l * (l + 1) >> 1;
    }
    return res;
}