#include "bits/stdc++.h"

using namespace std;

bool f(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int maximumPrimeDifference(vector<int> &nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < nums.size() && f(nums[l++]));
    while (r >= 0 && f(nums[r--]));
    return r - l;
}