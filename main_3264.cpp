#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;

vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
    struct cmp {
        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            return a.first == b.first ? a.second > b.second : a.first > b.first;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    for (int i = 0; i < nums.size(); ++i) {
        q.emplace(nums[i], i);
    }
    for (int i = 0; i < k; ++i) {
        pair<int, int> p = q.top();
        q.pop();
        nums[p.second] = (p.first * multiplier) % MOD;
        q.emplace(nums[p.second], p.second);
    }
    vector<int> res(nums.size(), -1);
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        res[p.second] = p.first;
    }
    return res;
}