#include "bits/stdc++.h"

using namespace std;

long long sumDigitDifferences(vector<int> &nums) {
    long long res = 0;
    vector<vector<int>> vs(10, vector<int>(10, 0));
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int idx = 0;
        while (num) {
            int x = num % 10;
            num /= 10;
            res += i - vs[idx++][x]++;
        }
    }
    return res;
}