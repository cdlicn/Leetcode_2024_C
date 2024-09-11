#include "bits/stdc++.h"

using namespace std;

// TODO 2555. 两个线段获得的最多奖品
int maximizeWin(vector<int> &prizePositions, int k) {
    int n = prizePositions.size();
    if (k * 2 + 1 >= prizePositions[n - 1] - prizePositions[0]) {
        return n;
    }
    int ans = 0, left = 0;
    vector<int> mx(n + 1);
    for (int right = 0; right < n; right++) {
        while (prizePositions[right] - prizePositions[left] > k) {
            left++;
        }
        ans = max(ans, mx[left] + right - left + 1);
        mx[right + 1] = max(mx[right], right - left + 1);
    }
    return ans;
}