#include "bits/stdc++.h"

using namespace std;

int maxNumberOfApples(vector<int> &weight) {
    sort(weight.begin(), weight.end());
    int n = 0, i = 0;
    for (i = 0; i < weight.size(); ++i) {
        n += weight[i];
        if (n > 5000) {
            return i;
        }
    }
    return i;
}