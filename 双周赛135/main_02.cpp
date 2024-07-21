#include "bits/stdc++.h"

using namespace std;

int minimumLength(string s) {
    int res = s.size();
    map<char, int> m;
    for (const auto &c: s) {
        m[c]++;
        if (m[c] == 3) {
            m[c] = 1;
            res -= 2;
        }
    }
    return res;
}