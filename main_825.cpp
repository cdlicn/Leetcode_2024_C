#include "bits/stdc++.h"

using namespace std;

int numFriendRequests(vector<int> &ages) {
    int cnt[121]{};
    for (const auto &age: ages) {
        cnt[age]++;
    }
    int res = 0;
    int s = 0;
    int y = 1;
    for (int x = 0; x < 121; x++) {
        s += cnt[x];
        if (y * 2 <= x + 14) {
            s -= cnt[y];
            y++;
        }
        if (s > 0) {
            res += cnt[x] * s - cnt[x];
        }
    }
    return res;
}