#include "bits/stdc++.h"

using namespace std;

vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x) {
    unordered_map<int, int> map;
    int n = 1;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == x) {
            map[n++] = i;
        }
    }
    vector<int> res;
    for (const auto &q: queries) {
        if (q < n) {
            res.push_back(map[q]);
        } else {
            res.push_back(-1);
        }
    }
    return res;
}