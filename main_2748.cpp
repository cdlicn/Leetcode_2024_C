#include "bits/stdc++.h"

using namespace std;

int countBeautifulPairs(vector<int> &nums) {
    int res = 0, cnt[10]{};
    for (auto num: nums) {
        for (int i = 1; i < 10; ++i) {
            if (cnt[i] && gcd(i, num % 10) == 1) {
                res += cnt[i];
            }
        }
        while (num >= 10) {
            num /= 10;
        }
        cnt[num]++;
    }
    return res;
}