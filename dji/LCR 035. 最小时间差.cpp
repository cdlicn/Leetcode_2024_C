#include "bits/stdc++.h"

using namespace std;

int findMinDifference(vector<string> &timePoints) {
    vector<int> vs;
    for (const auto &time: timePoints) {
        vs.emplace_back(stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3)));
    }
    ranges::sort(vs);
    vs.emplace_back(vs[0] + 24 * 60);
    int res = INT_MAX;
    for (int i = 1; i < vs.size(); ++i) {
        res = min(res, vs[i] - vs[i - 1]);
    }
    return res;
}