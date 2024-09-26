#include "bits/stdc++.h"

using namespace std;

int differenceOfSum(vector<int> &nums) {
    int res = 0;
    for (int num: nums) {
        res += num;
        while (num != 0) {
            res -= num % 10;
            num /= 10;
        }
    }
    return abs(res);
}