#include "bits/stdc++.h"

using namespace std;

int f(string num, string t) {
    int i = num.rfind(t[1]);
    if (i == string::npos || i == 0) {
        return num.size();
    }
    i = num.rfind(t[0], i - 1);
    if (i == string::npos) {
        return num.size();
    }
    return num.size() - i - 2;
}

int minimumOperations(string num) {
    int res = num.size();
    for (int i = num.size() - 1; i >= 0; i--) {
        if (num[i] == '0') {
            res--;
        }
    }
    res =
            min({res, f(num, "00"), f(num, "25"), f(num, "50"), f(num, "75")});
    return res;
}