#include "bits/stdc++.h"

using namespace std;

int countKConstraintSubstrings(string s, int k) {
    int res = 0;
    int cnt0 = 0;
    int cnt1 = 0;
    int lef = 0;
    for (int rig = 0; rig < s.size(); ++rig) {
        if (s[rig] == '0') {
            cnt0++;
        } else {
            cnt1++;
        }
        while (cnt0 > k && cnt1 > k) {
            if (s[lef] == '0') {
                cnt0--;
            } else {
                cnt1--;
            }
            lef++;
        }
        res += rig - lef + 1;
    }
    return res;
}