#include "bits/stdc++.h"

using namespace std;

bool judge(string &s1, string &s2) {
    int i = 0;
    for (char c: s2) {
        if (s1[i] == c && ++i == s1.size()) {
            return true;
        }
    }
    return false;
}

int findLUSlength(vector<string> &strs) {
    int n = strs.size();
    int res = -1;
    for (int i = 0; i < n; ++i) {
        if ((int) strs[i].size() > res) {
            bool f = true;
            for (int j = 0; j < n; ++j) {
                if (i != j && strs[i].size() <= strs[j].size() && judge(strs[i], strs[j])) {
                    f = false;
                    break;
                }
            }
            if (f) {
                res = strs[i].size();
            }
        }
    }
    return res;
}