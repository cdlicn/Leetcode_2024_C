#include "bits/stdc++.h"

using namespace std;

// TODO 1870. 准时到达的列车最小时速
int minSpeedOnTime(vector<int> &dist, double hour) {
    int n = dist.size();
    long long h100 = round(hour * 100); // 下面不会用到任何浮点数
    long long delta = h100 - (n - 1) * 100;
    if (delta <= 0) { // 无法到达终点
        return -1;
    }

    int max_dist = ranges::max(dist);
    if (h100 <= n * 100) { // 特判
        // 见题解中的公式
        return max(max_dist, (int) ((dist.back() * 100 - 1) / delta + 1));
    }

    auto check = [&](int v) -> bool {
        long long t = 0;
        for (int i = 0; i < n - 1; i++) {
            t += (dist[i] - 1) / v + 1;
        }
        return (t * v + dist.back()) * 100 <= h100 * v;
    };

    int h = h100 / (n * 100);
    int left = 0, right = (max_dist - 1) / h + 1;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        (check(mid) ? right : left) = mid;
    }
    return right;
}
