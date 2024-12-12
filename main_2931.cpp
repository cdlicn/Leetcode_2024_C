#include "bits/stdc++.h"

using namespace std;

long long maxSpending(vector<vector<int>> &values) {
//    vector<long long> a;
//    for (const auto &value: values) {
//        for (const auto &v: value) {
//            a.emplace_back(v);
//        }
//    }
//    sort(a.begin(), a.end());
//    long long res = 0;
//    for (int i = 1; i <= a.size(); ++i) {
//        res += a[i - 1] * i;
//    }
//    return res;
    struct cmp {
        bool operator()(int &a, int &b) {
            return a > b;
        }
    };
    priority_queue<int, vector<int>, cmp> pq;
    for (const auto &value: values) {
        for (const auto &v: value) {
            pq.push(v);
        }
    }
    long long res = 0;
    long long i = 1;
    while (!pq.empty()) {
        res += pq.top() * i;
        pq.pop();
        i++;
    }
    return res;
}