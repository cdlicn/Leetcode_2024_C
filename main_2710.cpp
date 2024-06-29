#include "bits/stdc++.h"

using namespace std;

string removeTrailingZeros(string num) {
    return num.substr(0, num.find_last_not_of('0') + 1);
}