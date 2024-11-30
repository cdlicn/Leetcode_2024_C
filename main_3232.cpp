#include "bits/stdc++.h"

using namespace std;

bool canAliceWin(vector<int> &nums) {
    int n = 0;
    for (const auto &num: nums) {
        n += num < 10 ? num : -num;
    }
    return n != 0;
}