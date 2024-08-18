#include "bits/stdc++.h"

using namespace std;

bool checkRecord(string s) {
    int n = 0;
    int a = 0;
    for (const auto &item: s) {
        if (item == 'A') {
            a++;
        }
        if (item == 'L') {
            n++;
        } else {
            n = 0;
        }
        if (n == 3 || a == 2) {
            return false;
        }
    }
    return true;
}