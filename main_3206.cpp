#include "bits/stdc++.h"

using namespace std;

int numberOfAlternatingGroups(vector<int> &colors) {
    int res = 0;
    int n = colors.size();
    for (int i = 1; i <= n; ++i) {
        if (colors[i % n] != colors[i - 1] && colors[i % n] != colors[(i + 1) % n]) {
            res++;
        }
    }
    return res;
}