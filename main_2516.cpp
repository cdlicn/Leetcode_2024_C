#include "bits/stdc++.h"

using namespace std;

int takeCharacters(string s, int k) {
    int cnt[3]{};
    for (auto &c: s) {
        cnt[c - 'a']++;
    }
    if (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
        return -1;
    }
    int lef = 0;
    int res = 0;
    for (int rig = 0; rig < s.size(); rig++) {
        int c = s[rig] - 'a';
        cnt[c]--;
        while (cnt[c] < k) {
            cnt[s[lef] - 'a']++;
            lef++;
        }
        res = max(res, rig - lef + 1);
    }
    return s.size() - res;
}