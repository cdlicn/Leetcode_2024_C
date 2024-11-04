#include "bits/stdc++.h"

using namespace std;

bool judgeSquareSum(int c) {
    for (int a = 0; a * a <= c / 2; a++) {
        int b = sqrt(c - a * a);
        if (b * b + a * a == c) {
            return true;
        }
    }
    return false;
}