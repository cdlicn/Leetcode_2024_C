#include "bits/stdc++.h"

using namespace std;

vector<int> getSneakyNumbers(vector<int> &nums) {
    vector<int> res;
    map<int, int> m;
    for (const auto &n: nums) {
        m[n] += 1;
        if (m[n] == 2) {
            res.push_back(n);
        }
    }
    return res;
}