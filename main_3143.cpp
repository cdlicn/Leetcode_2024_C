#include "bits/stdc++.h"

using namespace std;

int maxPointsInsideSquare(vector<vector<int>> &points, string s) {
    map<int, vector<char>> m;
    for (int i = 0; i < points.size(); ++i) {
        int k = max(abs(points[i][0]), abs(points[i][1]));
        m[k].emplace_back(s[i]);
    }
    int res = 0;
    vector<int> cs(26, 0);
    for (auto &[k, vs]: m) {
        for (const auto &v: vs) {
            if (cs[v - 'a'] == 1) {
                return res;
            }
            cs[v - 'a']++;
        }
        res += vs.size();
    }
    return res;
}