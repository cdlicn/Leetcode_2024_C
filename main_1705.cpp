#include "bits/stdc++.h"

using namespace std;

struct cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.first > b.first;
    }
};

int eatenApples(vector<int> &apples, vector<int> &days) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    int n = apples.size(), time = 0, res = 0;
    while (time < n || !q.empty()) {
        if (time < n && apples[time] > 0) {
            q.emplace(time + days[time] - 1, apples[time]);
        }
        while (!q.empty() && q.top().first < time) {
            q.pop();
        }
        if (!q.empty()) {
            pair<int, int> cur = q.top();
            q.pop();
            cur.second--;
            if (cur.second > 0 && cur.first > time) {
                q.emplace(cur);
            }
            res++;
        }
        time++;
    }
    return res;
}