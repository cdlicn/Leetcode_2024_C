#include "bits/stdc++.h"

using namespace std;

int minElement(vector<int> &nums) {
    int res = INT_MAX;
    for (auto n: nums) {
        int tmp = 0;
        while (n) {
            tmp += n % 10;
            n /= 10;
        }
        res = min(res, tmp);
    }
    return res;
}