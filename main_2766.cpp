#include "bits/stdc++.h"

using namespace std;

vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector<int> &moveTo) {
    unordered_set<int> s(nums.begin(), nums.end());
    int n = moveFrom.size();
    for (int i = 0; i < n; ++i) {
        s.erase(moveFrom[i]);
        s.emplace(moveTo[i]);
    }
    vector<int> res(s.begin(), s.end());
    sort(res.begin(), res.end());
    return res;
}