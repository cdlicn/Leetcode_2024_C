#include "bits/stdc++.h"

using namespace std;

int calculateTime(string keyboard, string word) {
    vector<int> v(26, -1);
    for (int i = 0; i < keyboard.size(); ++i) {
        v[keyboard[i] - 'a'] = i;
    }
    int res = 0;
    int idx = 0;
    for (const auto &w: word) {
        res += abs(v[w - 'a'] - idx);
        idx = v[w - 'a'];
    }
    return res;
}