#include "bits/stdc++.h"

using namespace std;

bool threeConsecutiveOdds(vector<int> &arr) {
    int n = 0;
    for (const auto &item: arr) {
        if (item % 2 == 1) {
            n++;
        } else {
            n = 0;
        }
        if (n == 3) {
            return true;
        }
    }
    return false;
}