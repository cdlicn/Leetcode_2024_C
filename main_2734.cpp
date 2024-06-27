#include "bits/stdc++.h"

using namespace std;

string smallestString(string s) {
    int lef = 0;
    int n = s.size();
    while (lef < n && s[lef] == 'a') {
        lef++;
    }
    if (lef == n) {
        s[n - 1] = 'z';
        return s;
    }
    while (lef < n && s[lef] != 'a') {
        s[lef]--;
        lef++;
    }
    return s;
}