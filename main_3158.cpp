#include "bits/stdc++.h"

using namespace std;

int duplicateNumbersXOR(vector<int> &nums) {
    int res = 0;
    map<int, int> m;
    for (const auto &num: nums) {
        m[num]++;
        if (m[num] == 2) {
            res ^= num;
        }
    }
    return res;
}