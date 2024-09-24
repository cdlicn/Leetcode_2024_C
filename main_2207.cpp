#include "bits/stdc++.h"

using namespace std;

long long maximumSubsequenceCount(string text, string pattern) {
    long long res = 0;
    long long n1 = 0, n2 = 0;
    for (const auto &c: text) {
        if (c == pattern[1]) {
            n2++;
            res += n1;
        }
        if (c == pattern[0]) {
            n1++;
        }
    }
    return res + max(n1, n2);
}