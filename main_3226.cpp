#include "bits/stdc++.h"

using namespace std;

int minChanges(int n, int k) {
    int res = 0;
    while (n || k) {
        if (n & 1 && !(k & 1)) {
            res++;
        } else if (!(n & 1) && k & 1) {
            return -1;
        }
        n >>= 1;
        k >>= 1;
    }
    return res;
}