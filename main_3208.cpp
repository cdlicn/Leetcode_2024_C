#include "bits/stdc++.h"

using namespace std;

int numberOfAlternatingGroups(vector<int> &colors, int k) {
    int res = 0;
    int n = colors.size();
    int s = 1;
    for (int i = 1; i < n + k - 1; ++i) {
        if (colors[i % n] != colors[(i - 1) % n]) {
            s++;
        } else {
            s = 1;
        }
        if (s >= k) {
            res++;
        }
    }
    return res;
}