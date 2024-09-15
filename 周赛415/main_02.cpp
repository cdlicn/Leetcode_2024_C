#include "bits/stdc++.h"

using namespace std;

long long maxScore(vector<int> &a, vector<int> &b) {
    int n = b.size();
    vector<long long> dp1(n, INT_MIN);
    long long mx = INT_MIN;
    for (int i = 0; i <= n - 4; i++) {
        mx = max(mx, (long long) b[i] * (long long) a[0]);
        dp1[i] = mx;
    }
    mx = INT_MIN;
    vector<long long> dp2(n, INT_MIN);
    for (int i = 1; i <= n - 3; i++) {
        mx = max(mx, dp1[i - 1] + (long long) b[i] * (long long) a[1]);
        dp2[i] = mx;
    }
    mx = INT_MIN;
    vector<long long> dp3(n, INT_MIN);
    for (int i = 2; i <= n - 2; i++) {
        mx = max(mx, dp2[i - 1] + (long long) b[i] * (long long) a[2]);
        dp3[i] = mx;
    }
    mx = INT_MIN;
    vector<long long> dp4(n, INT_MIN);
    for (int i = 3; i <= n - 1; i++) {
        mx = max(mx, dp3[i - 1] + (long long) b[i] * (long long) a[3]);
        dp4[i] = mx;
    }
    return dp4[n - 1];
}