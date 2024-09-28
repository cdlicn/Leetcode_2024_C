#include "bits/stdc++.h"

using namespace std;

long long maximumTotalSum(vector<int> &maximumHeight) {
    sort(maximumHeight.begin(), maximumHeight.end());
    int n = maximumHeight.size();
    int pre = maximumHeight[n - 1];
    long long res = maximumHeight[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (maximumHeight[i] >= pre) {
            if (pre == 1) {
                return -1;
            }
            res += pre - 1;
            pre -= 1;
        } else {
            res += maximumHeight[i];
            pre = maximumHeight[i];
        }
    }
    return res;
}