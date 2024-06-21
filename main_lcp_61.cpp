#include "bits/stdc++.h"

using namespace std;

int temperatureTrend(vector<int> &temperatureA, vector<int> &temperatureB) {
    int res = 0;
    int tmp = 0;
    int n = temperatureA.size();
    for (int i = 0; i < n - 1; ++i) {
        int a = temperatureA[i + 1] - temperatureA[i];
        int b = temperatureB[i + 1] - temperatureB[i];
        if ((a == 0 && b == 0) || (a > 0 && b > 0) || (a < 0 && b < 0)) {
            tmp++;
        } else {
            res = max(res, tmp);
            tmp = 0;
        }
    }
    return max(res, tmp);
}