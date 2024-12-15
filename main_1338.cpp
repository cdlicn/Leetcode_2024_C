#include "bits/stdc++.h"

using namespace std;

int minSetSize(vector<int> &arr) {
    map<int, int> m;
    for (const auto &a: arr) {
        m[a]++;
    }
    vector<int> vs;
    for (const auto &[_, v]: m) {
        vs.emplace_back(v);
    }
    sort(vs.begin(), vs.end(), greater());
    int n = 0;
    for (int i = 0; i < vs.size(); ++i) {
        n += vs[i];
        if (n >= arr.size() / 2) {
            return i + 1;
        }
    }
    return -1;
}