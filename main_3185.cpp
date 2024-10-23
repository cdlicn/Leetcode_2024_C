#include "bits/stdc++.h"

using namespace std;

long long countCompleteDayPairs(vector<int> &hours) {
    long long res = 0;
    vector<int> cnt(24, 0);
    for (const auto &hour: hours) {
        res += cnt[(24 - (hour % 24)) % 24];
        cnt[hour % 24]++;
    }
    return res;
}