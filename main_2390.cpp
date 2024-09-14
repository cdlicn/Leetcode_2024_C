#include "bits/stdc++.h"

using namespace std;

string removeStars(string s) {
    string res = "";
    for (const auto &c: s) {
        if (c == '*') {
            res.pop_back();
        } else {
            res += c;
        }
    }
    return res;
}