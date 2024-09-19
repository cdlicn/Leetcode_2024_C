#include "bits/stdc++.h"

using namespace std;

int longestContinuousSubstring(string s) {
    int res = 1, tmp = 1, n = s.size();
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1] + 1) {
            tmp++;
        } else {
            res = max(res, tmp);
            tmp = 1;
        }
    }
    return max(res, tmp);
}