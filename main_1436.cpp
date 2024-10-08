#include"bits/stdc++.h"

using namespace std;

string destCity(vector<vector<string>> &paths) {
    unordered_set<string> st;
    for (auto &p: paths) {
        st.insert(p[0]);
    }
    for (auto &p: paths) {
        if (!st.contains(p[1])) {
            return p[1];
        }
    }
    return "";
}