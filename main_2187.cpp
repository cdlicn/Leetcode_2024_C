#include "bits/stdc++.h"

using namespace std;

// TODO 2187. 完成旅途的最少时间
long long minimumTime(vector<int> &time, int totalTrips) {
    auto check = [&](long long x) -> bool {
        long long sum = 0;
        for (int t: time) {
            sum += x / t;
            if (sum >= totalTrips) {
                return true;
            }
        }
        return false;
    };

    auto [min_t, max_t] = ranges::minmax(time);
    int avg = (totalTrips - 1) / time.size() + 1;
    // 循环不变量：check(left) 恒为 false
    long long left = (long long) min_t * avg - 1;
    // 循环不变量：check(right) 恒为 true
    long long right = min((long long) max_t * avg, (long long) min_t * totalTrips);
    while (left + 1 < right) { // 开区间 (left, right) 不为空
        long long mid = (left + right) / 2;
        (check(mid) ? right : left) = mid;
    }
    // 此时 left 等于 right-1
    // check(left) = false 且 check(right) = true，所以答案是 right
    return right; // 最小的 true
}