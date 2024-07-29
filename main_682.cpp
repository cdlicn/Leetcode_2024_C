#include "bits/stdc++.h"

using namespace std;

int calPoints(vector<string> &operations) {
    vector<int> vec;
    int a, b;
    for (auto &v: operations) {
        if (v == "+") {
            a = *(vec.end() - 1);
            b = *(vec.end() - 2);
            vec.emplace_back(a + b);
        } else if (v == "D") {
            vec.emplace_back(2 * *(vec.end() - 1));
        } else if (v == "C") {
            vec.erase(vec.end());
        } else {
            vec.emplace_back(stoi(v));
        }
    }
    int res = 0;
    for (auto &v: vec) {
        res += v;
    }
    return res;
}