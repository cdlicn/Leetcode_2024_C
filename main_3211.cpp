#include "bits/stdc++.h"

using namespace std;

vector<string> res;

void dfs(string s, int n) {
    if (n == 0) {
        res.emplace_back(s);
        return;
    }
    n--;
    dfs(s + "1", n);
    if (s.empty() || s.back() == '1') {
        dfs(s + "0", n);
    }
}

vector<string> validStrings(int n) {
    dfs("", n);
    return res;
}