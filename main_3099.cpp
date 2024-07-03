#include "bits/stdc++.h"

using namespace std;

int sumOfTheDigitsOfHarshadNumber(int x) {
    int v = x;
    int s = 0;
    while (x) {
        s += x % 10;
        x /= 10;
    }
    return v % s ? -1 : s;
}