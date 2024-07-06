#include "bits/stdc++.h"

using namespace std;

long long countAlternatingSubarrays(vector<int> &nums) {
    long long res = 0;
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i] != nums[i - 1]) {
            cnt++;
        } else {
            cnt = 1;
        }
        res += cnt;
    }
    return res;
}