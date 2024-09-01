#include "bits/stdc++.h"

using namespace std;

struct Compare {
    bool operator()(pair<double, int> a, pair<double, int> b) {
        return a.first < b.first;
    }
};

long long minDamage(int power, vector<int> &damage, vector<int> &health) {
    long long res = 0;
    long long sum = 0;
    int n = damage.size();
    priority_queue<pair<double, int>, vector<pair<double, int>>, Compare> pq;
    for (int i = 0; i < n; ++i) {
        sum += damage[i];
        health[i] = ceil(health[i] / (power * 1.0));
        double p1 = (1.0 * damage[i]) / health[i];
        pq.emplace(p1, i);
    }
    while (!pq.empty()) {
        int idx = pq.top().second;
        pq.pop();
        res += sum * health[idx];
        sum -= damage[idx];
    }
    return res;
}