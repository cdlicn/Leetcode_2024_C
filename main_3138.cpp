#include "bits/stdc++.h"

using namespace std;

int minAnagramLength(string s) {
    int n = s.length();
    for (int k = 1; k <= n / 2; k++) {
        if (n % k) {
            continue;
        }
        array<int, 26> cnt0{};
        for (int j = 0; j < k; j++) {
            cnt0[s[j] - 'a']++;
        }
        bool ok = true;
        for (int i = k * 2; i <= n; i += k) {
            array<int, 26> cnt{};
            for (int j = i - k; j < i; j++) {
                cnt[s[j] - 'a']++;
            }
            if (cnt != cnt0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return k;
        }
    }
    return n;
}