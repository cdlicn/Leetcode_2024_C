#include "bits/stdc++.h"

using namespace std;

// TODO 1675. 数组的最小偏移量
int minimumDeviation(vector<int> &nums) {
    int p_max = 1;
    for (int a: nums) {
        while (a % 2 == 0) {
            a /= 2;
        }
        p_max = max(p_max, a);
    }
    vector<int> upper;
    int min = p_max;
    for (int a: nums) {
        if (a % 2 == 1) {
            a *= 2;
        }
        while (a >= 2 * p_max) {
            a /= 2;
        }
        if (a >= p_max) {
            upper.push_back(a);
        }
        min = std::min(min, a);
    }
    sort(upper.begin(), upper.end());
    int ans = upper.back() - min;
    for (int i = upper.size() - 1; upper[i] > p_max; i -= 1) {
        min = std::min(min, upper[i] / 2);
        ans = std::min(ans, upper[i - 1] - min);
    }
    return ans;
}