#include "bits/stdc++.h"

using namespace std;

string clearDigits(string s) {
    string res = "";
    for (const auto &c: s) {
        if (isdigit(c)) {
            res.pop_back();
        } else {
            res += c;
        }
    }
    return res;
}