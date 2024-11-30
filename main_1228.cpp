#include "bits/stdc++.h"

using namespace std;

int missingNumber(vector<int> &arr) {
    int n = arr.size();
    int dif = (arr[n - 1] - arr[0]) / n;
    for (int i = 1; i < n; ++i) {
        if (arr[i] - arr[i - 1] != dif) {
            return arr[i - 1] + dif;
        }
    }
    return arr[0];
}