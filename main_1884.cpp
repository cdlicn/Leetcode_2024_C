#include "bits/stdc++.h"

using namespace std;

int twoEggDrop(int n) {
    int res = 0;
    while (n > 0) {
        n -= ++res;
    }
    return res;
}